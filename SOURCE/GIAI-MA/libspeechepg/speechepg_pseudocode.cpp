// ============================================================================
// RECONSTRUCTED C++ VERIFICATION & PSEUDOCODE HARNESS: speechepg_pseudocode.cpp
// Target Library: libspeechepg.so (18,256 bytes, ELF64 AArch64)
// Module: Standalone Verification Suite & Complete Symbol / Disassembly Reference
// ============================================================================
// Tệp kiểm thử độc lập và đối chiếu toàn bộ 55 biểu tượng `.dynsym` (34 hàm nhập
// + 18 hàm xuất xưởng), cấu trúc ABI 24-byte `SpeechEngineHandler`, 48-byte
// `SpeechPluginListener` (vtable `0x007c18`), phép chia có dấu mẫu PCM 16-bit
// (`cinc + asr #1` tại `0x002f10` & `0x003000`), mã lỗi tràn bộ đệm `-1801`
// (`-0x709` tại `0x003130`) và tự động tách luồng callback khi `type == 1002`
// (`0x3ea` tại `0x00230c`).
// ============================================================================

#include "speechepg_types.h"
#include "speechepg_sdk_client.h"
#include "speechepg_jni_bridge.h"
#include "speechepg_interface.h"

#include <cmath>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

namespace speechepg::verification {

// ============================================================================
// 1. COMPLETE .DYNSYM SYMBOL TABLE METADATA (55 ENTRIES: [000]..[054])
// Bảng ánh xạ đầy đủ 55 biểu tượng trong .dynsym (0x000450..0x000978)
// ============================================================================
struct DynsymRecord {
    uint32_t    index;
    uint64_t    vaddr;
    uint32_t    size_bytes;
    bool        is_exported;
    const char* mangled_name;
};

static constexpr DynsymRecord kSpeechEpgDynsymTable[52] = {
    // 34 Imported Symbols ([003]..[036], SHN_UNDEF)
    {  3, 0x000000ULL,   0, false, "_ZnwmRKSt9nothrow_t" },
    {  4, 0x000000ULL,   0, false, "_ZN3lab6speech6client7OptionsC1Ev" },
    {  5, 0x000000ULL,   0, false, "_ZN3lab6speech6client7Options9SetOptionERKNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEERKd" },
    {  6, 0x000000ULL,   0, false, "__cxa_atexit" },
    {  7, 0x000000ULL,   0, false, "_Znwm" },
    {  8, 0x000000ULL,   0, false, "_ZN3lab6speech6client6Engine10GetVersionEv" },
    {  9, 0x000000ULL,   0, false, "_ZN3lab6speech6client6Engine4InitEPNS1_7OptionsE" },
    { 10, 0x000000ULL,   0, false, "__stack_chk_fail" },
    { 11, 0x000000ULL,   0, false, "licbag_set_java_vm" },
    { 12, 0x000000ULL,   0, false, "_ZdlPv" },
    { 13, 0x000000ULL,   0, false, "_ZN3lab6speech6client6Engine13SendDirectiveEiRKNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEE" },
    { 14, 0x000000ULL,   0, false, "_ZN3lab6speech6client7Options9SetOptionERKNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEESB_" },
    { 15, 0x000000ULL,   0, false, "_ZN3lab6speech6client6Engine17IsEngineSupportedEPKc" },
    { 16, 0x000000ULL,   0, false, "_ZN3lab6speech6client6EngineC1Ev" },
    { 17, 0x000000ULL,   0, false, "__android_log_print" },
    { 18, 0x000000ULL,   0, false, "_ZN3lab6speech6client6Engine7ProcessEPKsib" },
    { 19, 0x000000ULL,   0, false, "_ZN3lab6speech6client7Options9SetOptionERKNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEERKi" },
    { 20, 0x000000ULL,   0, false, "_ZSt7nothrow" },
    { 21, 0x000000ULL,   0, false, "_ZN3lab6speech6client14DefaultOptionsEPNS1_7OptionsE" },
    { 22, 0x000000ULL,   0, false, "_ZN3lab6speech6client6Engine11AddListenerEPNS1_8ListenerE" },
    { 23, 0x000000ULL,   0, false, "_ZNK3lab6speech6client7Options7IsValidEv" },
    { 24, 0x000000ULL,   0, false, "_ZN3lab6speech6client6EngineD1Ev" },
    { 25, 0x000000ULL,   0, false, "__cxa_finalize" },
    { 26, 0x000000ULL,   0, false, "_ZN3lab6speech6client7Options9SetOptionERKNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEERKb" },
    { 27, 0x000000ULL,   0, false, "abort" },
    { 28, 0x000000ULL,   0, false, "JNI_SetAssetManager" },
    { 29, 0x000000ULL,   0, false, "_ZN3lab6speech6client12EngineResult8ToStringEv" },
    { 30, 0x000000ULL,   0, false, "_ZN3lab6speech6client6Engine5ResetEv" },
    { 31, 0x000000ULL,   0, false, "memcpy" },
    { 32, 0x000000ULL,   0, false, "JNI_OnLoad_UUID" },
    { 33, 0x000000ULL,   0, false, "_ZN3lab6speech6client6Engine4FeedEPKsi" },
    { 34, 0x000000ULL,   0, false, "_ZN3lab6speech6client6Engine11FetchResultEi" },
    { 35, 0x000000ULL,   0, false, "strlen" },
    { 36, 0x000000ULL,   0, false, "_ZN3lab6speech6client7OptionsD1Ev" },

    // 18 Exported Symbols ([037]..[054], defined in .text 0x001f00..0x003244)
    { 37, 0x002f78ULL,  68, true,  "Java_com_bytedance_speech_speechengine_bridge_SpeechPluginBridge_resetEngineToNative" },
    { 38, 0x002b80ULL, 308, true,  "Java_com_bytedance_speech_speechengine_bridge_SpeechPluginBridge_setOptionDoubleToNative" },
    { 39, 0x002cb4ULL, 196, true,  "Java_com_bytedance_speech_speechengine_bridge_SpeechPluginBridge_initEngineToNative" },
    { 40, 0x002d78ULL, 344, true,  "Java_com_bytedance_speech_speechengine_bridge_SpeechPluginBridge_sendDirectiveToNative" },
    { 41, 0x002a4cULL, 308, true,  "Java_com_bytedance_speech_speechengine_bridge_SpeechPluginBridge_setOptionIntToNative" },
    { 42, 0x0023dcULL,   8, true,  "Java_com_bytedance_speech_speechengine_log_1tracker_SpeechLogTracker_getInstanceToNative" },
    { 43, 0x0023e8ULL, 148, true,  "Java_com_bytedance_speech_speechengine_bridge_SpeechPluginBridge_getVersionToNative" },
    { 44, 0x00247cULL, 100, true,  "Java_com_bytedance_speech_speechengine_bridge_SpeechPluginBridge_isEngineSupportedToNative" },
    { 45, 0x003070ULL, 284, true,  "Java_com_bytedance_speech_speechengine_bridge_SpeechPluginBridge_fetchResultToNative" },
    { 46, 0x001f00ULL, 128, true,  "JNI_OnLoad" },
    { 47, 0x002728ULL, 488, true,  "Java_com_bytedance_speech_speechengine_bridge_SpeechPluginBridge_setOptionStringToNative" },
    { 48, 0x0026b0ULL, 120, true,  "Java_com_bytedance_speech_speechengine_bridge_SpeechPluginBridge_destroyEngineToNative" },
    { 49, 0x00318cULL, 188, true,  "Java_com_bytedance_speech_speechengine_bridge_SpeechPluginBridge_fetchStringResultToNative" },
    { 50, 0x0024e0ULL, 464, true,  "Java_com_bytedance_speech_speechengine_bridge_SpeechPluginBridge_createEngineToNative" },
    { 51, 0x002ed0ULL, 168, true,  "Java_com_bytedance_speech_speechengine_bridge_SpeechPluginBridge_feedAudioToNative" },
    { 52, 0x0023e4ULL,   4, true,  "Java_com_bytedance_speech_speechengine_log_1tracker_SpeechLogTracker_writeLogToNative" },
    { 53, 0x002910ULL, 316, true,  "Java_com_bytedance_speech_speechengine_bridge_SpeechPluginBridge_setOptionBooleanToNative" },
    { 54, 0x002fbcULL, 180, true,  "Java_com_bytedance_speech_speechengine_bridge_SpeechPluginBridge_processAudioToNative" }
};

// ============================================================================
// 2. GATE 1: ELF64 GEOMETRY, .DYNSYM & VTABLE (.DATA.REL.RO 0x007c18) VERIFICATION
// Kiểm tra cấu trúc ELF64 (18,256 B), 55 biểu tượng .dynsym và vtable 0x007c18
// ============================================================================
bool VerifyElf64AndVtableLayout() {
    using Geo = ::lab::speech::client::SpeechEpgElf64Geometry;
    using Int = ::lab::speech::client::SpeechEpgInternalVaddrs;

    if (Geo::kFileSizeBytes != 18256ULL || Geo::kDynsymTotalEntries != 55U) {
        return false;
    }
    if (Geo::kImportedSymbolCount != 34U || Geo::kExportedSymbolCount != 18U) {
        return false;
    }

    uint32_t imported = 0;
    uint32_t exported = 0;
    for (const auto& rec : kSpeechEpgDynsymTable) {
        if (rec.is_exported) {
            ++exported;
            if (rec.vaddr < Geo::kSecTextVaddr || rec.vaddr >= Geo::kSecTextEndVaddr) {
                return false;
            }
        } else {
            ++imported;
        }
    }
    if (imported != 34U || exported != 18U) {
        return false;
    }

    // Verify SpeechPluginListener vtable in .data.rel.ro @ 0x007c18 (vptr = 0x007c28 = +0x10)
    if (Int::kDataRelRo_ListenerVptr != Int::kDataRelRo_ListenerVtable + 0x10ULL) {
        return false;
    }
    if (Int::kSub_Listener_Dtor_D1Ev != 0x001fa0ULL ||
        Int::kSub_Listener_Dtor_D0Ev != 0x002058ULL ||
        Int::kSub_Listener_OnMessage  != 0x002248ULL) {
        return false;
    }
    return true;
}

// ============================================================================
// 3. GATE 2: ABI STRUCT LAYOUTS (HANDLER 24B, LISTENER 48B, CALLBACK ENV 16B)
// Kiểm tra bố cục struct ABI: SpeechEngineHandler (24B), SpeechPluginListener (48B)
// ============================================================================
bool VerifyAbiStructLayouts() {
    if (sizeof(speechepg::bridge::SpeechEngineHandler) != 24U) {
        return false;
    }
    if (sizeof(speechepg::bridge::JniCallbackEnvironment) != 16U) {
        return false;
    }
    if (speechepg::bridge::SpeechPluginListener::kAbiSize != 48U) {
        return false;
    }

    // Verify failure path of createEngineToNative when callback object is nullptr (0x002138 -> -1LL)
    int64_t bad_handle = Java_com_bytedance_speech_speechengine_bridge_SpeechPluginBridge_createEngineToNative(
        nullptr, nullptr, nullptr);
    if (bad_handle != -1LL) {
        return false;
    }

    // Verify SpeechLogTracker_getInstanceToNative @ 0x0023dc returns -1LL (`mov x0, #-1; ret`)
    int64_t tracker = Java_com_bytedance_speech_speechengine_log_1tracker_SpeechLogTracker_getInstanceToNative(
        nullptr, nullptr);
    if (tracker != -1LL) {
        return false;
    }
    return true;
}

// ============================================================================
// 4. GATE 3: SIGNED PCM16 SAMPLE COUNT ARITHMETIC (`cinc + asr #1`) & DSP MATH
// Kiểm tra phép chia 2 có dấu (`0x002f10..0x002f18` & `0x003000..0x00300c`) và DSP
// ============================================================================
bool VerifyPcm16SampleArithmeticAndDsp() {
    auto aarch64_byte_to_samples = [](int32_t w22) -> int32_t {
        // 0x002f10: cmp w22, #0
        // 0x002f14: cinc w8, w22, lt
        // 0x002f18: asr w2, w8, #1
        int32_t w8 = (w22 < 0) ? (w22 + 1) : w22;
        return w8 >> 1;
    };

    if (aarch64_byte_to_samples(3200) != 1600) return false;
    if (aarch64_byte_to_samples(3201) != 1600) return false;
    if (aarch64_byte_to_samples(-1)   != 0)    return false;
    if (aarch64_byte_to_samples(-3)   != -1)   return false;
    if (aarch64_byte_to_samples(0)    != 0)    return false;

    std::vector<int16_t> pcm(160);
    for (size_t i = 0; i < pcm.size(); ++i) {
        double phase = 2.0 * 3.14159265358979323846 * 1000.0 * static_cast<double>(i) / 16000.0;
        pcm[i] = static_cast<int16_t>(std::round(16384.0 * std::sin(phase)));
    }

    int cb_obj = 1;
    int64_t handle = Java_com_bytedance_speech_speechengine_bridge_SpeechPluginBridge_createEngineToNative(
        nullptr, nullptr, &cb_obj);
    if (handle == -1LL) {
        return false;
    }

    auto* handler = reinterpret_cast<speechepg::bridge::SpeechEngineHandler*>(handle);
    if (handler->options == nullptr || !handler->options->IsValid()) {
        return false;
    }

    int32_t init_rc = Java_com_bytedance_speech_speechengine_bridge_SpeechPluginBridge_initEngineToNative(
        nullptr, nullptr, handle, &cb_obj);
    // Note: in libspeechepg.so (0x002cb4..0x002d74), handler->options is retained until destroyEngineToNative (0x0026e0)!
    if (init_rc != 0 || handler->options == nullptr) {
        return false;
    }

    int32_t feed_rc = Java_com_bytedance_speech_speechengine_bridge_SpeechPluginBridge_feedAudioToNative(
        nullptr, nullptr, handle,
        reinterpret_cast<const uint8_t*>(pcm.data()),
        static_cast<int32_t>(pcm.size() * sizeof(int16_t)));
    if (feed_rc != 0 || handler->engine->totalFedSamples() != 160) {
        return false;
    }
    if (handler->engine->lastRmsDbFs() <= -20.0 || handler->engine->lastRmsDbFs() >= -5.0) {
        return false;
    }

    Java_com_bytedance_speech_speechengine_bridge_SpeechPluginBridge_destroyEngineToNative(
        nullptr, nullptr, handle);
    return true;
}

// ============================================================================
// 5. GATE 4: FETCHRESULT BUFFER OVERFLOW GUARD (`-1801 = -0x709` @ 0x003130)
// Kiểm tra mã lỗi `-1801` (`-0x709`) khi bộ đệm đích nhỏ hơn kích thước kết quả
// ============================================================================
bool VerifyFetchResultBufferGuard() {
    int cb_obj = 2;
    int64_t handle = Java_com_bytedance_speech_speechengine_bridge_SpeechPluginBridge_createEngineToNative(
        nullptr, nullptr, &cb_obj);
    if (handle == -1LL) {
        return false;
    }
    if (Java_com_bytedance_speech_speechengine_bridge_SpeechPluginBridge_initEngineToNative(
            nullptr, nullptr, handle, &cb_obj) != 0) {
        return false;
    }

    std::vector<int16_t> pcm(80, 4096);
    if (Java_com_bytedance_speech_speechengine_bridge_SpeechPluginBridge_processAudioToNative(
            nullptr, nullptr, handle,
            reinterpret_cast<const uint8_t*>(pcm.data()),
            static_cast<int32_t>(pcm.size() * sizeof(int16_t)), 1U) != 0) {
        return false;
    }

    // 1. Small buffer (4 bytes) -> must return -1801 (-0x709 @ 0x003130)
    speechepg::jni::SimulatedByteArray tiny_buf;
    tiny_buf.bytes.resize(4U);
    int32_t small_rc = Java_com_bytedance_speech_speechengine_bridge_SpeechPluginBridge_fetchResultToNative(
        nullptr, nullptr, handle,
        ::lab::speech::client::SpeechEpgConstants::kMessageTypeFinalResult,
        &tiny_buf);
    if (small_rc != -1801) {
        return false;
    }

    // 2. Sufficient buffer (512 bytes) -> must return positive byte length
    speechepg::jni::SimulatedByteArray large_buf;
    large_buf.bytes.resize(512U);
    int32_t ok_rc = Java_com_bytedance_speech_speechengine_bridge_SpeechPluginBridge_fetchResultToNative(
        nullptr, nullptr, handle,
        ::lab::speech::client::SpeechEpgConstants::kMessageTypeFinalResult,
        &large_buf);
    if (ok_rc <= 10) {
        return false;
    }

    Java_com_bytedance_speech_speechengine_bridge_SpeechPluginBridge_destroyEngineToNative(
        nullptr, nullptr, handle);
    return true;
}

// ============================================================================
// 6. GATE 5: ONMESSAGE(1002 = 0x3EA) CALLBACK THREAD AUTO-DETACH (@ 0x00230c)
// Kiểm tra tự động gọi `DetachCallback()` khi `type == 1002` (`0x3ea` tại `0x00230c`)
// ============================================================================
bool VerifyOnMessageStopAutoDetach() {
    speechepg::bridge::SpeechPluginListener listener;
    int cb_obj = 3;
    if (listener.InitCallbackObject(&cb_obj) != 0) {
        return false;
    }

    listener.OnMessage(1001, "{\"event\":\"plugin_engine_start\"}");
    if (listener.callbackEnv().is_attached != 1U || listener.callbackEnv().callback_env == nullptr) {
        return false;
    }

    // Trigger MESSAGE_TYPE_ENGINE_STOP (1002 = 0x3ea @ 0x00230c) -> detaches thread!
    listener.OnMessage(1002, "{\"event\":\"plugin_engine_stop\"}");
    if (listener.callbackEnv().is_attached != 0U || listener.callbackEnv().callback_env != nullptr) {
        return false;
    }
    return true;
}

} // namespace speechepg::verification

#ifdef SPEECHEPG_STANDALONE_TEST
int main() {
    using namespace speechepg::verification;
    bool ok = VerifyElf64AndVtableLayout() &&
              VerifyAbiStructLayouts() &&
              VerifyPcm16SampleArithmeticAndDsp() &&
              VerifyFetchResultBufferGuard() &&
              VerifyOnMessageStopAutoDetach();
    std::cout << "[libspeechepg.so] Verification: " << (ok ? "PASS" : "FAIL") << "\n";
    return ok ? 0 : 1;
}
#endif
