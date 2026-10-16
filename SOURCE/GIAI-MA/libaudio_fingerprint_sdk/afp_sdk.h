// ==============================================================================
// NextAI OpenCut — High-Fidelity Video Editing & Vector Graphics Engine
// Module: libaudio_fingerprint_sdk — Audio Fingerprint SDK Top-Level Interface
// File: afp_sdk.h
// Description: Top-level SDK interface, lifecycle management, and JNI bindings
//              matching AArch64 binary opcodes in libaudio_fingerprint_sdk.so.
//
// Chú thích song ngữ: Tiếng Anh (EN) & Tiếng Việt (VN)
// ==============================================================================

#ifndef NEXTAI_OPENCUT_AFP_SDK_H_
#define NEXTAI_OPENCUT_AFP_SDK_H_

#include "afp_types.h"
#include "afp_landmark_detector.h"
#include "afp_peak_compressor.h"

#include <string>
#include <vector>
#include <memory>
#include <jni.h>

namespace audio_fingerprint_sdk {

class AFP_SDK {
public:
    /**
     * @brief AFP_SDK: Constructor.
     * Matches AArch64 opcode 0x9230 (212 bytes).
     * Initializes default parameters and landmark detector engine.
     */
    AFP_SDK();

    /**
     * @brief ~AFP_SDK: Destructor.
     * Matches AArch64 opcode 0x9304 (448 bytes).
     */
    virtual ~AFP_SDK();

    /**
     * @brief GetVersion: Returns SDK semantic version string ("0.0.3").
     * Matches AArch64 opcode 0x94c4 (16 bytes).
     */
    static std::string GetVersion();

    /**
     * @brief Reset: Resets internal state and clears processed audio frames.
     * Matches AArch64 opcode 0x956c (4 bytes).
     */
    void Reset();

    /**
     * @brief Process: Ingests raw audio PCM buffer (16-bit signed LE).
     * Matches AArch64 opcode 0x9570 (4 bytes).
     */
    int Process(unsigned char* pcm_data, int length_bytes);

    /**
     * @brief GetAudioFingerPrint: Generates Base64 or binary encoded fingerprint string.
     * Matches AArch64 opcode 0x9574 (340 bytes).
     */
    int GetAudioFingerPrint(std::string& out_fingerprint);

    /**
     * @brief Init: Configures custom sample rate and window size.
     */
    int Init(int sample_rate = kDefaultSampleRate,
             int frame_size = kDefaultFrameSize,
             int hop_size = kDefaultHopSize);

    // Telemetry getters
    size_t GetProcessedFrames() const;
    size_t GetDetectedLandmarksCount() const;

private:
    std::unique_ptr<landmark_peak_afp_t> detector_;
    bool initialized_;
    std::string version_;
};

} // namespace audio_fingerprint_sdk

// ==============================================================================
// EN: JNI Interface Exports for Android Java Runtime
// VN: Cầu nối JNI phục vụ ứng dụng Android NextAI OpenCut
// ==============================================================================
extern "C" {

JNIEXPORT jlong JNICALL
Java_com_nextai_opencut_afp_AudioFingerprintSDK_nativeCreate(JNIEnv* env, jclass clazz);

JNIEXPORT void JNICALL
Java_com_nextai_opencut_afp_AudioFingerprintSDK_nativeDestroy(JNIEnv* env, jclass clazz, jlong handle);

JNIEXPORT jint JNICALL
Java_com_nextai_opencut_afp_AudioFingerprintSDK_nativeProcess(JNIEnv* env, jclass clazz,
                                                              jlong handle, jbyteArray pcm_data, jint length);

JNIEXPORT jstring JNICALL
Java_com_nextai_opencut_afp_AudioFingerprintSDK_nativeGetFingerprint(JNIEnv* env, jclass clazz, jlong handle);

JNIEXPORT void JNICALL
Java_com_nextai_opencut_afp_AudioFingerprintSDK_nativeReset(JNIEnv* env, jclass clazz, jlong handle);

JNIEXPORT jstring JNICALL
Java_com_nextai_opencut_afp_AudioFingerprintSDK_nativeGetVersion(JNIEnv* env, jclass clazz);

} // extern "C"

#endif // NEXTAI_OPENCUT_AFP_SDK_H_
