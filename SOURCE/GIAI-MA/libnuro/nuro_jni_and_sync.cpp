// ============================================================================
// Clean-Room C++17 SyncChannel, Cacher, RestApiClient & Djinni JNI Bridge for libnuro.so
// Kênh đồng bộ SyncChannel, Cacher, RestApiClient & Cầu nối JNI Djinni C++17 sạch cho libnuro.so
// ============================================================================
#include "nuro_core.h"
#include <jni.h>
#include <deque>

namespace nuro {

// Reconstructed from sync_channel.cpp (0x07c7b4..0x07d200, 0xa8 __shared_ptr_emplace allocation)
// Tái dựng từ sync_channel.cpp (0x07c7b4..0x07d200, cấp phát 0xa8 bytes __shared_ptr_emplace)
class SyncChannelImpl final : public SyncChannel, public std::enable_shared_from_this<SyncChannelImpl> {
public:
    explicit SyncChannelImpl(SyncChannelOptions options)
        : options_(std::move(options)) {}

    ~SyncChannelImpl() override = default;

    void sync(const std::string& key, const std::string& payload) override {
        std::lock_guard<std::mutex> lock(mutex_);
        if (static_cast<int32_t>(stash_.size()) >= options_.max_stash_count && !stash_.empty()) {
            stash_.pop_front();
        }
        stash_.emplace_back(key, payload);
    }

    void flush() override {
        std::lock_guard<std::mutex> lock(mutex_);
        stash_.clear();
    }

private:
    SyncChannelOptions options_;
    std::mutex mutex_;
    std::deque<std::pair<std::string, std::string>> stash_;
};

// Reconstructed from 0x07c7b4..0x07c87c
// Tái dựng từ 0x07c7b4..0x07c87c
std::shared_ptr<SyncChannel> SyncChannel::create(const SyncChannelOptions& options) {
    return std::make_shared<SyncChannelImpl>(options);
}

} // namespace nuro

// ============================================================================
// Djinni JNI CppProxy Entry Points (0x08e0c4 .. 0x09c594)
// Các điểm vào JNI CppProxy của Djinni (0x08e0c4 .. 0x09c594)
// ============================================================================
extern "C" {

// 0x093dd0..0x093dec
JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved) {
    (void)vm;
    (void)reserved;
    return JNI_VERSION_1_6;
}

// 0x093dec..0x093df0
JNIEXPORT void JNICALL JNI_OnUnload(JavaVM* vm, void* reserved) {
    (void)vm;
    (void)reserved;
}

// 0x08eac4..0x08eb3c: Java_com_lemon_nuro_Conversation_00024CppProxy_native_1setRunMode
JNIEXPORT void JNICALL Java_com_lemon_nuro_Conversation_00024CppProxy_native_1setRunMode(
    JNIEnv* env, jobject thiz, jlong nativeRef, jobject j_mode) {
    (void)env;
    (void)thiz;
    (void)j_mode;
    auto* ptr = reinterpret_cast<std::shared_ptr<nuro::Conversation>*>(nativeRef);
    if (ptr && *ptr) {
        (*ptr)->setRunMode(nuro::RunMode::NORMAL);
    }
}

// 0x08ec0c..0x08ec6c: Java_com_lemon_nuro_Conversation_00024CppProxy_native_1recoverRemoteSection
JNIEXPORT jboolean JNICALL Java_com_lemon_nuro_Conversation_00024CppProxy_native_1recoverRemoteSection(
    JNIEnv* env, jobject thiz, jlong nativeRef) {
    (void)env;
    (void)thiz;
    auto* ptr = reinterpret_cast<std::shared_ptr<nuro::Conversation>*>(nativeRef);
    if (ptr && *ptr) {
        return (*ptr)->recoverRemoteSection() ? JNI_TRUE : JNI_FALSE;
    }
    return JNI_FALSE;
}

// 0x08ec6c..0x08ecc8: Java_com_lemon_nuro_Conversation_00024CppProxy_native_1cancelRecoverRemoteSection
JNIEXPORT void JNICALL Java_com_lemon_nuro_Conversation_00024CppProxy_native_1cancelRecoverRemoteSection(
    JNIEnv* env, jobject thiz, jlong nativeRef) {
    (void)env;
    (void)thiz;
    auto* ptr = reinterpret_cast<std::shared_ptr<nuro::Conversation>*>(nativeRef);
    if (ptr && *ptr) {
        (*ptr)->cancelRecoverRemoteSection();
    }
}

} // extern "C"
