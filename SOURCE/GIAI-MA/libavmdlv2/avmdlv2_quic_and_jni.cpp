// ============================================================================
// Clean-Room C++17 QUIC State Manager, Link Quality & JNI Bridge for libavmdlv2.so
// Quản lý trạng thái QUIC, Chất lượng liên kết & Cầu nối JNI C++17 sạch cho libavmdlv2.so
// ============================================================================
#include "avmdlv2_core.h"
#include <jni.h>

namespace com {
namespace ss {
namespace ttmio {

MDLLinkQualitySampleInfo::MDLLinkQualitySampleInfo(bool quic, int64_t rtt, int64_t bw, int64_t loss,
                                                   int32_t code, const char* h, int64_t ts, int32_t net)
    : is_quic(quic),
      rtt_ms(rtt),
      bw_bps(bw),
      loss_ppm(loss),
      status_code(code),
      host(h ? h : ""),
      sample_ts(ts),
      net_type(net) {}

void MDLLinkQualitySampleInfo::printInfo(const char* tag) const {
    (void)tag;
}

MDLQuicStateManager* MDLQuicStateManager::getInstance() {
    static MDLQuicStateManager* s_inst = new MDLQuicStateManager();
    return s_inst;
}

bool MDLQuicStateManager::isQuicBroken(const char* host) const {
    std::lock_guard<std::mutex> lock(mutex_);
    if (global_broken_) return true;
    if (!host) return false;
    auto it = broken_hosts_.find(host);
    return it != broken_hosts_.end() && it->second;
}

void MDLQuicStateManager::resetQuicBrokenStatus() {
    std::lock_guard<std::mutex> lock(mutex_);
    global_broken_ = false;
    broken_hosts_.clear();
}

void MDLQuicStateManager::markQuicBroken(const char* host) {
    std::lock_guard<std::mutex> lock(mutex_);
    if (host) {
        broken_hosts_[host] = true;
    } else {
        global_broken_ = true;
    }
}

int64_t MDLQuicStateManager::calAvgSpeed(const std::list<int64_t>& samples) const {
    if (samples.empty()) return 0;
    int64_t sum = 0;
    for (int64_t v : samples) {
        sum += v;
    }
    return sum / static_cast<int64_t>(samples.size());
}

// Reconstructed from 0x115c00..0x115ce8
int32_t ff_convertStatusCodeToMdlErr(int32_t http_status, bool is_https) noexcept {
    if (http_status >= 200 && http_status < 300) return 0;
    return is_https ? -(http_status + 2000) : -(http_status + 1000);
}

// Reconstructed from 0x11fafc..0x11fb20
bool needRedirect(int32_t http_status) noexcept {
    return http_status == 301 || http_status == 302 || http_status == 303 ||
           http_status == 307 || http_status == 308;
}

} // namespace ttmio
} // namespace ss
} // namespace com

extern "C" {

// 0x039868..0x039978: JNI_OnLoad (returns JNI_VERSION_1_4 = 0x00010004)
JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved) {
    (void)reserved;
    if (!vm) return -1;
    JNIEnv* env = nullptr;
    if (vm->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION_1_4) != JNI_OK) {
        return -1;
    }
    return JNI_VERSION_1_4;
}

// 0x039978..0x0399ac: JNI_OnUnload
JNIEXPORT void JNICALL JNI_OnUnload(JavaVM* vm, void* reserved) {
    (void)vm;
    (void)reserved;
}

} // extern "C"
