/**
 * @file alog_jni.cpp
 * @brief ByteDance ALog Native JNI Bridge Implementation.
 *        Hiện thực JNI native đăng ký động cho hệ thống nhật ký ByteDance ALog.
 */

#include "alog_jni.h"
#include "alog_core.h"
#include <stdlib.h>
#include <string.h>

static JavaVM* g_vm = NULL;
static jclass g_native_callback_clazz = NULL;

static void parse_jstring(JNIEnv* env, jstring jstr, char* out_buf, size_t max_len) {
    if (!jstr) {
        out_buf[0] = '\0';
        return;
    }
    const char* chars = env->GetStringUTFChars(jstr, NULL);
    if (chars) {
        strncpy(out_buf, chars, max_len - 1);
        out_buf[max_len - 1] = '\0';
        env->ReleaseStringUTFChars(jstr, chars);
    } else {
        out_buf[0] = '\0';
    }
}

JNIEXPORT jlong JNICALL Java_com_bytedance_android_alog_Alog_nativeCreate(
    JNIEnv* env, jclass clazz,
    jint mode, jboolean enableSyslog, jstring logDir, jstring cacheDir,
    jint maxDirSizeMb, jint maxFileSizeMb, jint maxHistoryDays, jstring prefix,
    jint compressorType, jint compressLevel, jstring pubKey,
    jint encryptorType, jint bufferSize, jint asyncQueueSize, jint minLogLevel,
    jint flushIntervalSec, jint cacheSizeLimit, jstring processName,
    jlong subModuleMask, jboolean enableMemoryDump, jint reservedFlag) {

    (void)clazz;
    AlogConfig cfg;
    memset(&cfg, 0, sizeof(AlogConfig));

    cfg.mode = mode;
    cfg.enable_syslog = (bool)enableSyslog;
    parse_jstring(env, logDir, cfg.log_dir, sizeof(cfg.log_dir));
    parse_jstring(env, cacheDir, cfg.cache_dir, sizeof(cfg.cache_dir));
    cfg.max_dir_size_mb = maxDirSizeMb;
    cfg.max_file_size_mb = maxFileSizeMb;
    cfg.max_history_days = maxHistoryDays;
    parse_jstring(env, prefix, cfg.file_prefix, sizeof(cfg.file_prefix));
    cfg.compressor_type = compressorType;
    cfg.compress_level = compressLevel;
    parse_jstring(env, pubKey, cfg.pub_key, sizeof(cfg.pub_key));
    cfg.encryptor_type = encryptorType;
    cfg.buffer_size = bufferSize;
    cfg.async_queue_size = asyncQueueSize;
    cfg.min_log_level = minLogLevel;
    cfg.flush_interval_sec = flushIntervalSec;
    cfg.cache_size_limit = cacheSizeLimit;
    parse_jstring(env, processName, cfg.process_name, sizeof(cfg.process_name));
    cfg.sub_module_mask = (int64_t)subModuleMask;
    cfg.enable_memory_dump = (bool)enableMemoryDump;
    cfg.reserved_flag = reservedFlag;

    AlogHandle handle = NULL;
    int ret = alog_create(&handle, &cfg);
    if (ret != 0 || !handle) {
        return 0;
    }

    return (jlong)(intptr_t)handle;
}

JNIEXPORT void JNICALL Java_com_bytedance_android_alog_Alog_nativeWrite(
    JNIEnv* env, jclass clazz, jlong handle, jint level, jstring tag, jstring msg) {

    (void)clazz;
    if (!handle || !msg) return;

    const char* c_tag = tag ? env->GetStringUTFChars(tag, NULL) : NULL;
    const char* c_msg = env->GetStringUTFChars(msg, NULL);

    if (c_msg) {
        alog_write((AlogHandle)(intptr_t)handle, (int)level, c_tag, c_msg);
        env->ReleaseStringUTFChars(msg, c_msg);
    }
    if (c_tag) {
        env->ReleaseStringUTFChars(tag, c_tag);
    }
}

JNIEXPORT void JNICALL Java_com_bytedance_android_alog_Alog_nativeWriteAsyncMsg(
    JNIEnv* env, jclass clazz, jlong handle, jint level, jstring tag, jstring msg, jlong arg1, jlong arg2) {

    (void)clazz;
    if (!handle || !msg) return;

    const char* c_tag = tag ? env->GetStringUTFChars(tag, NULL) : NULL;
    const char* c_msg = env->GetStringUTFChars(msg, NULL);

    if (c_msg) {
        AlogInstance* inst = (AlogInstance*)(intptr_t)handle;
        if (inst && inst->async_worker) {
            alog_async_worker_enqueue(inst->async_worker, (int)level, c_tag, c_msg, (int64_t)arg1, (int64_t)arg2);
        } else {
            alog_write((AlogHandle)(intptr_t)handle, (int)level, c_tag, c_msg);
        }
        env->ReleaseStringUTFChars(msg, c_msg);
    }
    if (c_tag) {
        env->ReleaseStringUTFChars(tag, c_tag);
    }
}

JNIEXPORT void JNICALL Java_com_bytedance_android_alog_Alog_nativeAsyncFlush(
    JNIEnv* env, jclass clazz, jlong handle) {
    (void)env; (void)clazz;
    alog_async_flush((AlogHandle)(intptr_t)handle);
}

JNIEXPORT void JNICALL Java_com_bytedance_android_alog_Alog_nativeSyncFlush(
    JNIEnv* env, jclass clazz, jlong handle) {
    (void)env; (void)clazz;
    alog_sync_flush((AlogHandle)(intptr_t)handle);
}

JNIEXPORT void JNICALL Java_com_bytedance_android_alog_Alog_nativeTimedSyncFlush(
    JNIEnv* env, jclass clazz, jlong handle, jint timeoutMs) {
    (void)env; (void)clazz;
    alog_timed_sync_flush((AlogHandle)(intptr_t)handle, (int)timeoutMs);
}

JNIEXPORT void JNICALL Java_com_bytedance_android_alog_Alog_nativeSetLevel(
    JNIEnv* env, jclass clazz, jlong handle, jint level) {
    (void)env; (void)clazz;
    alog_set_level((AlogHandle)(intptr_t)handle, (int)level);
}

JNIEXPORT void JNICALL Java_com_bytedance_android_alog_Alog_nativeSetSyslog(
    JNIEnv* env, jclass clazz, jlong handle, jboolean enable) {
    (void)env; (void)clazz;
    alog_set_syslog((AlogHandle)(intptr_t)handle, (bool)enable);
}

JNIEXPORT void JNICALL Java_com_bytedance_android_alog_Alog_nativeDestroy(
    JNIEnv* env, jclass clazz, jlong handle) {
    (void)env; (void)clazz;
    alog_destroy((AlogHandle)(intptr_t)handle);
}

JNIEXPORT jlong JNICALL Java_com_bytedance_android_alog_Alog_nativeGetLegacyWriteFuncAddr(
    JNIEnv* env, jclass clazz) {
    (void)env; (void)clazz;
    return (jlong)(intptr_t)&alog_write_default_instance;
}

JNIEXPORT jlong JNICALL Java_com_bytedance_android_alog_Alog_nativeGetLegacyFlushFuncAddr(
    JNIEnv* env, jclass clazz) {
    (void)env; (void)clazz;
    return (jlong)(intptr_t)&alog_async_flush;
}

JNIEXPORT jlong JNICALL Java_com_bytedance_android_alog_Alog_nativeGetLegacyGetLogFileDirFuncAddr(
    JNIEnv* env, jclass clazz) {
    (void)env; (void)clazz;
    return 0;
}

JNIEXPORT void JNICALL Java_com_bytedance_android_alog_Alog_nativeSetDefaultInstance(
    JNIEnv* env, jclass clazz, jlong handle) {
    (void)env; (void)clazz;
    alog_set_default_instance((AlogHandle)(intptr_t)handle);
}

JNIEXPORT void JNICALL Java_com_bytedance_android_alog_Alog_nativeUpdateAlogCacheSize(
    JNIEnv* env, jclass clazz, jint cacheSize) {
    (void)env; (void)clazz;
    AlogHandle def = alog_get_default_instance();
    if (def) {
        AlogInstance* inst = (AlogInstance*)def;
        if (inst->buffer) {
            alog_buffer_resize(inst->buffer, (size_t)cacheSize);
        }
    }
}

JNIEXPORT jlong JNICALL Java_com_bytedance_android_alog_Alog_nativeGetNativeWriteFuncAddr(
    JNIEnv* env, jclass clazz) {
    (void)env; (void)clazz;
    return (jlong)(intptr_t)&alog_write;
}

JNIEXPORT jlong JNICALL Java_com_bytedance_android_alog_Alog_nativeGetNativeWriteAsyncFuncAddr(
    JNIEnv* env, jclass clazz) {
    (void)env; (void)clazz;
    return (jlong)(intptr_t)&alog_write_default_instance_async;
}

JNIEXPORT jlong JNICALL Java_com_bytedance_android_alog_Alog_nativeGetNativeInitFuncAddr(
    JNIEnv* env, jclass clazz) {
    (void)env; (void)clazz;
    return (jlong)(intptr_t)&init_async_logging;
}

JNIEXPORT void JNICALL Java_com_bytedance_android_alog_Alog_nativeSetEnableWrite(
    JNIEnv* env, jclass clazz, jint enable) {
    (void)env; (void)clazz;
    AlogHandle def = alog_get_default_instance();
    if (def) {
        AlogInstance* inst = (AlogInstance*)def;
        inst->enable_write = (enable != 0);
    }
}

// ============================================================================
// DYNAMIC JNI REGISTRATION TABLE (Khớp VAddr 0x14008 trong libalog.so)
// ============================================================================

static const JNINativeMethod gAlogMethods[18] = {
    {"nativeCreate", "(IZLjava/lang/String;Ljava/lang/String;IIILjava/lang/String;IILjava/lang/String;IIIIIILjava/lang/String;JZI)J", (void*)&Java_com_bytedance_android_alog_Alog_nativeCreate},
    {"nativeWrite", "(JILjava/lang/String;Ljava/lang/String;)V", (void*)&Java_com_bytedance_android_alog_Alog_nativeWrite},
    {"nativeWriteAsyncMsg", "(JILjava/lang/String;Ljava/lang/String;JJ)V", (void*)&Java_com_bytedance_android_alog_Alog_nativeWriteAsyncMsg},
    {"nativeAsyncFlush", "(J)V", (void*)&Java_com_bytedance_android_alog_Alog_nativeAsyncFlush},
    {"nativeSyncFlush", "(J)V", (void*)&Java_com_bytedance_android_alog_Alog_nativeSyncFlush},
    {"nativeTimedSyncFlush", "(JI)V", (void*)&Java_com_bytedance_android_alog_Alog_nativeTimedSyncFlush},
    {"nativeSetLevel", "(JI)V", (void*)&Java_com_bytedance_android_alog_Alog_nativeSetLevel},
    {"nativeSetSyslog", "(JZ)V", (void*)&Java_com_bytedance_android_alog_Alog_nativeSetSyslog},
    {"nativeDestroy", "(J)V", (void*)&Java_com_bytedance_android_alog_Alog_nativeDestroy},
    {"nativeGetLegacyWriteFuncAddr", "()J", (void*)&Java_com_bytedance_android_alog_Alog_nativeGetLegacyWriteFuncAddr},
    {"nativeGetLegacyFlushFuncAddr", "()J", (void*)&Java_com_bytedance_android_alog_Alog_nativeGetLegacyFlushFuncAddr},
    {"nativeGetLegacyGetLogFileDirFuncAddr", "()J", (void*)&Java_com_bytedance_android_alog_Alog_nativeGetLegacyGetLogFileDirFuncAddr},
    {"nativeSetDefaultInstance", "(J)V", (void*)&Java_com_bytedance_android_alog_Alog_nativeSetDefaultInstance},
    {"nativeUpdateAlogCacheSize", "(I)V", (void*)&Java_com_bytedance_android_alog_Alog_nativeUpdateAlogCacheSize},
    {"nativeGetNativeWriteFuncAddr", "()J", (void*)&Java_com_bytedance_android_alog_Alog_nativeGetNativeWriteFuncAddr},
    {"nativeGetNativeWriteAsyncFuncAddr", "()J", (void*)&Java_com_bytedance_android_alog_Alog_nativeGetNativeWriteAsyncFuncAddr},
    {"nativeGetNativeInitFuncAddr", "()J", (void*)&Java_com_bytedance_android_alog_Alog_nativeGetNativeInitFuncAddr},
    {"nativeSetEnableWrite", "(I)V", (void*)&Java_com_bytedance_android_alog_Alog_nativeSetEnableWrite}
};

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved) {
    (void)reserved;
    g_vm = vm;

    JNIEnv* env = NULL;
    if (vm->GetEnv((void**)&env, JNI_VERSION_1_6) != JNI_OK) {
        return JNI_ERR;
    }

    // Register 18 methods on class com/bytedance/android/alog/Alog
    // Đăng ký động 18 phương thức trên lớp com/bytedance/android/alog/Alog
    jclass clazz = env->FindClass("com/bytedance/android/alog/Alog");
    if (!clazz) {
        return JNI_ERR;
    }

    if (env->RegisterNatives(clazz, gAlogMethods, 18) != 0) {
        return JNI_ERR;
    }

    // Cache NativeCallback class reference
    // Lưu tham chiếu lớp NativeCallback phục vụ gọi ngược khi xóa log
    jclass cb_clazz = env->FindClass("com/bytedance/android/alog/NativeCallback");
    if (cb_clazz) {
        g_native_callback_clazz = (jclass)env->NewGlobalRef(cb_clazz);
    }

    return JNI_VERSION_1_6;
}
