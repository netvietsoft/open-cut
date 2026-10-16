// ==============================================================================
// NextAI OpenCut — High-Fidelity Video Editing & Vector Graphics Engine
// Module: libaudio_fingerprint_sdk — Audio Fingerprint SDK Top-Level Interface
// File: afp_sdk.cpp
// Description: Implementation of AFP_SDK top-level API, Base64 serialization,
//              and JNI bindings matching AArch64 binary opcodes.
//
// Chú thích song ngữ: Tiếng Anh (EN) & Tiếng Việt (VN)
// ==============================================================================

#include "afp_sdk.h"
#include <algorithm>
#include <cstring>
#include <sstream>

namespace audio_fingerprint_sdk {

// Static Base64 character lookup table
static const char kBase64Chars[] =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz"
    "0123456789+/";

static std::string Base64Encode(const unsigned char* data, size_t len) {
    std::string out;
    out.reserve(((len + 2) / 3) * 4);

    size_t i = 0;
    while (i < len) {
        uint32_t octet_a = i < len ? data[i++] : 0;
        uint32_t octet_b = i < len ? data[i++] : 0;
        uint32_t octet_c = i < len ? data[i++] : 0;

        uint32_t triple = (octet_a << 16) | (octet_b << 8) | octet_c;

        out.push_back(kBase64Chars[(triple >> 18) & 0x3F]);
        out.push_back(kBase64Chars[(triple >> 12) & 0x3F]);
        out.push_back(i > len + 1 ? '=' : kBase64Chars[(triple >> 6) & 0x3F]);
        out.push_back(i > len ? '=' : kBase64Chars[triple & 0x3F]);
    }

    return out;
}

/**
 * @brief AFP_SDK: Constructor.
 * Matches AArch64 opcode 0x9230 (212 bytes).
 */
AFP_SDK::AFP_SDK()
    : initialized_(false), version_("0.0.3") {
    detector_ = std::make_unique<landmark_peak_afp_t>();
    initialized_ = true;
}

/**
 * @brief ~AFP_SDK: Destructor.
 * Matches AArch64 opcode 0x9304 (448 bytes).
 */
AFP_SDK::~AFP_SDK() {
    detector_.reset();
    initialized_ = false;
}

/**
 * @brief GetVersion: Returns SDK semantic version ("0.0.3").
 * Matches AArch64 opcode 0x94c4 (16 bytes).
 * Binary string address: 0x17c30 ("0.0.3").
 */
std::string AFP_SDK::GetVersion() {
    return "0.0.3";
}

/**
 * @brief Reset: Resets internal state.
 * Matches AArch64 opcode 0x956c (4 bytes).
 * Single branch instruction: b #0x2f90 -> landmark_peak_afp_t::reset().
 */
void AFP_SDK::Reset() {
    if (detector_) {
        detector_->reset();
    }
}

/**
 * @brief Process: Ingests raw audio PCM buffer.
 * Matches AArch64 opcode 0x9570 (4 bytes).
 * Single branch instruction: b #0x3bd4 -> landmark_peak_afp_t::process().
 */
int AFP_SDK::Process(unsigned char* pcm_data, int length_bytes) {
    if (!detector_ || !initialized_) {
        return static_cast<int>(AFPStatus::NOT_INITIALIZED);
    }
    return detector_->process(pcm_data, length_bytes);
}

/**
 * @brief GetAudioFingerPrint: Generates Base64 encoded fingerprint string.
 * Matches AArch64 opcode 0x9574 (340 bytes).
 */
int AFP_SDK::GetAudioFingerPrint(std::string& out_fingerprint) {
    out_fingerprint.clear();
    if (!detector_ || !initialized_) {
        return static_cast<int>(AFPStatus::NOT_INITIALIZED);
    }

    std::vector<unsigned char> binary_payload;
    int status = detector_->get_afp(binary_payload);
    if (status != static_cast<int>(AFPStatus::SUCCESS) || binary_payload.empty()) {
        return status;
    }

    // Prepend 32-bit big-endian size header (opcode 0x6950)
    PeakCompressor::write_size_ahead(binary_payload);

    // Encode to Base64 string
    out_fingerprint = Base64Encode(binary_payload.data(), binary_payload.size());
    return static_cast<int>(AFPStatus::SUCCESS);
}

/**
 * @brief Init: Configures custom sample rate and window size.
 */
int AFP_SDK::Init(int sample_rate, int frame_size, int hop_size) {
    landmark_peak_para_t para;
    para.sample_rate = sample_rate;
    para.frame_size = frame_size;
    para.hop_size = hop_size;

    if (!detector_) {
        detector_ = std::make_unique<landmark_peak_afp_t>();
    }
    detector_->init(para);
    initialized_ = true;
    return static_cast<int>(AFPStatus::SUCCESS);
}

size_t AFP_SDK::GetProcessedFrames() const {
    return detector_ ? detector_->GetTotalFramesProcessed() : 0;
}

size_t AFP_SDK::GetDetectedLandmarksCount() const {
    return detector_ ? detector_->GetLandmarks().size() : 0;
}

} // namespace audio_fingerprint_sdk

// ==============================================================================
// EN: JNI Implementation for Android Platform Integration
// VN: Triển khai cầu nối JNI cho nền tảng Android
// ==============================================================================
extern "C" {

JNIEXPORT jlong JNICALL
Java_com_nextai_opencut_afp_AudioFingerprintSDK_nativeCreate(JNIEnv* env, jclass clazz) {
    auto* sdk = new audio_fingerprint_sdk::AFP_SDK();
    return reinterpret_cast<jlong>(sdk);
}

JNIEXPORT void JNICALL
Java_com_nextai_opencut_afp_AudioFingerprintSDK_nativeDestroy(JNIEnv* env, jclass clazz, jlong handle) {
    auto* sdk = reinterpret_cast<audio_fingerprint_sdk::AFP_SDK*>(handle);
    delete sdk;
}

JNIEXPORT jint JNICALL
Java_com_nextai_opencut_afp_AudioFingerprintSDK_nativeProcess(JNIEnv* env, jclass clazz,
                                                              jlong handle, jbyteArray pcm_data, jint length) {
    auto* sdk = reinterpret_cast<audio_fingerprint_sdk::AFP_SDK*>(handle);
    if (!sdk || !pcm_data || length <= 0) return -1;

    jbyte* bytes = env->GetByteArrayElements(pcm_data, nullptr);
    if (!bytes) return -1;

    int res = sdk->Process(reinterpret_cast<unsigned char*>(bytes), length);
    env->ReleaseByteArrayElements(pcm_data, bytes, JNI_ABORT);
    return res;
}

JNIEXPORT jstring JNICALL
Java_com_nextai_opencut_afp_AudioFingerprintSDK_nativeGetFingerprint(JNIEnv* env, jclass clazz, jlong handle) {
    auto* sdk = reinterpret_cast<audio_fingerprint_sdk::AFP_SDK*>(handle);
    if (!sdk) return nullptr;

    std::string fp;
    sdk->GetAudioFingerPrint(fp);
    return env->NewStringUTF(fp.c_str());
}

JNIEXPORT void JNICALL
Java_com_nextai_opencut_afp_AudioFingerprintSDK_nativeReset(JNIEnv* env, jclass clazz, jlong handle) {
    auto* sdk = reinterpret_cast<audio_fingerprint_sdk::AFP_SDK*>(handle);
    if (sdk) {
        sdk->Reset();
    }
}

JNIEXPORT jstring JNICALL
Java_com_nextai_opencut_afp_AudioFingerprintSDK_nativeGetVersion(JNIEnv* env, jclass clazz) {
    std::string ver = audio_fingerprint_sdk::AFP_SDK::GetVersion();
    return env->NewStringUTF(ver.c_str());
}

} // extern "C"
