// ============================================================================
// File: ttr_render_types.h
// Target: libttr.so (625,192 bytes)
// SHA-256: 38c13f772c29f2a6b03c5523b74730be6727dfc9c3de457b1e09fe32578d6f6f
// Task ID: TASK-143-RECONSTRUCTION-LIBTTR / TASK_SO_101_libttr
// Architecture: AArch64 (ELF64 Little-Endian, .eh_frame_hdr @ 0x08ab40 = 3,386 FDEs)
// ============================================================================
// [EN] Clean-room C++17 type definitions, ABI struct layouts, TTRMessage / TTRUtilsTool /
//      TTRAudioEngine / TTRVideoEngine interfaces, and OpenGL ES 2.0/3.0 dynamic stub
//      table declarations for ByteDance TikTok Render Engine (libttr.so).
// [VN] Định nghĩa kiểu dữ liệu C++17 tái tạo sạch, bố cục struct ABI, giao diện
//      TTRMessage / TTRUtilsTool / TTRAudioEngine / TTRVideoEngine và bảng stub động
//      OpenGL ES 2.0/3.0 cho ByteDance TikTok Render Engine (libttr.so).
// ============================================================================

#pragma once

#include <cstdint>
#include <cstddef>
#include <ctime>
#include <string>
#include <vector>
#include <unordered_map>
#include <mutex>
#include <memory>
#include <jni.h>

struct AVFrame;

namespace ttr_render {

constexpr uint32_t kTtrBinarySizeBytes    = 625192U;
constexpr uint32_t kTtrEhFrameHdrVa       = 0x08ab40U;
constexpr uint32_t kTtrTotalFdeCount      = 3386U;
constexpr uint32_t kTtrExportSymbolCount  = 490U;
constexpr uint32_t kTtrImportSymbolCount  = 161U;
constexpr uint32_t kTtrTextSectionVa      = 0x01c750U;
constexpr uint32_t kTtrTextSectionSize    = 0x048250U;
constexpr uint32_t kTtrRodataSectionVa    = 0x0649a0U;
constexpr uint32_t kTtrRodataSectionSize  = 0x00f3d4U;
constexpr uint32_t kTtrDataSectionVa      = 0x09c000U;
constexpr uint32_t kTtrBssSectionVa       = 0x09c138U;
constexpr uint32_t kTtrGlStubWrapperCount = 358U; // .bss 0x09c140..0x09cc68
constexpr uint32_t kTtrJniVersion16       = 0x00010006U;

using TTRMsgKey = int32_t;

struct TTRAudioInfo {
    int32_t sample_rate{48000};
    int32_t channels{2};
    int32_t sample_fmt{1};
    int32_t buffer_frames{1024};
};

struct TTREnvConfig {
    void* shared_egl_context{nullptr};
    int32_t gles_version{3};
    int32_t max_width{1920};
    int32_t max_height{1080};
    bool enable_hardware_buffer{true};
};

struct TTRVideoFrame {
    int32_t width{0};
    int32_t height{0};
    int32_t format{0};
    int64_t pts_us{0};
    uint8_t* planes[3]{nullptr, nullptr, nullptr};
    int32_t strides[3]{0, 0, 0};
};

// [EN] TTRAudioEngine ABI layout (0x58 = 88 bytes), verified from TTRAudioEngine::TTRAudioEngine() @ 0x029200:
//      +0x00: vptr (_ZTVN10ttr_render14TTRAudioEngineE + 0x10)
//      +0x08: void* mPipelineOrDevice (checked at SetVolume @ 0x029574, GetLatency @ 0x02969c, SetExtLatency @ 0x0296b0)
//      +0x10..0x27: internal pointers (cleared via stur q0, [x0, #8] & stur q0, [x0, #0x18])
//      +0x28: uint16_t mFlags (strh wzr, [x0, #0x28] @ 0x029224)
//      +0x2c: float mVolume = 1.0f (0x3f800000 stored at 0x029204, read at GetVolume @ 0x0295a4)
//      +0x30: double mSpeed = 1.0  (0x3ff0000000000000 stored at 0x02920c)
//      +0x38: uint64_t mFrameCount (str xzr, [x0, #0x38] @ 0x029228)
//      +0x40: int32_t mDeviceId = -1 (mov w8, #-1; str w8, [x0, #0x40] @ 0x029214)
//      +0x44..0x57: zero-initialized state fields
// [VN] Bố cục ABI của TTRAudioEngine (0x58 = 88 byte), xác minh từ TTRAudioEngine::TTRAudioEngine() @ 0x029200.
struct alignas(8) TTRAudioEngineAbiLayout {
    void* vptr;                // +0x00
    void* pipeline_ptr;        // +0x08
    uint64_t reserved_10;      // +0x10
    uint64_t reserved_18;      // +0x18
    uint64_t reserved_20;      // +0x20
    uint16_t flags_28;         // +0x28
    uint16_t pad_2a;           // +0x2a
    float volume_2c;           // +0x2c (initialized to 0x3f800000 = 1.0f)
    double speed_30;           // +0x30 (initialized to 0x3ff0000000000000 = 1.0)
    uint64_t frame_count_38;   // +0x38
    int32_t device_id_40;      // +0x40 (initialized to -1)
    uint8_t tail_zero_44[20];  // +0x44..0x57
};
static_assert(sizeof(TTRAudioEngineAbiLayout) == 0x58, "TTRAudioEngineAbiLayout must be 0x58 bytes");
static_assert(offsetof(TTRAudioEngineAbiLayout, volume_2c) == 0x2c, "volume_2c must be at +0x2c");
static_assert(offsetof(TTRAudioEngineAbiLayout, speed_30) == 0x30, "speed_30 must be at +0x30");
static_assert(offsetof(TTRAudioEngineAbiLayout, device_id_40) == 0x40, "device_id_40 must be at +0x40");

// [EN] TTRMessage (0x022b38..0x023b87): key-value message container.
// [VN] TTRMessage (0x022b38..0x023b87): bộ chứa thông điệp khóa-giá trị.
class TTRMessage {
public:
    TTRMessage();
    TTRMessage(const TTRMessage& other); // 0x022c74
    virtual ~TTRMessage();               // 0x022b78

    static TTRMessage* Create();         // 0x022b38
    static void Delete(TTRMessage* msg); // 0x022c60
    void Clear();                        // 0x022c6c

    void SetInt32(TTRMsgKey key, int32_t val);        // 0x0230fc
    void SetInt64(TTRMsgKey key, int64_t val);        // 0x023534
    void SetFloat(TTRMsgKey key, float val);          // 0x0235ac
    void SetDouble(TTRMsgKey key, double val);        // 0x023628
    void SetPointer(TTRMsgKey key, void* val);        // 0x0236a4
    void SetString(TTRMsgKey key, const char* val);   // 0x02371c

    bool FindInt32(TTRMsgKey key, int32_t* out) const;       // 0x0237cc
    bool FindInt64(TTRMsgKey key, int64_t* out) const;       // 0x023850
    bool FindFloat(TTRMsgKey key, float* out) const;         // 0x023884
    bool FindDouble(TTRMsgKey key, double* out) const;       // 0x0238c0
    bool FindPointer(TTRMsgKey key, void** out) const;       // 0x0238f4
    bool FindString(TTRMsgKey key, std::string& out) const;  // 0x023928
    void Dump() const;                                       // 0x023b58

private:
    std::unordered_map<TTRMsgKey, int32_t> i32_map_;
    std::unordered_map<TTRMsgKey, int64_t> i64_map_;
    std::unordered_map<TTRMsgKey, float> f32_map_;
    std::unordered_map<TTRMsgKey, double> f64_map_;
    std::unordered_map<TTRMsgKey, void*> ptr_map_;
    std::unordered_map<TTRMsgKey, std::string> str_map_;
};

// [EN] TTRUtilsTool (0x023b88..0x0241cf): bit-exact utility methods verified from AArch64 opcodes.
// [VN] TTRUtilsTool (0x023b88..0x0241cf): các phương thức tiện ích khớp bit từ mã máy AArch64.
class TTRUtilsTool {
public:
    static int GetTimespec(struct timespec& ts) noexcept;                  // 0x023b88
    static int64_t GetCurrentTimeMs() noexcept;                            // 0x023bc8
    static int64_t GetCurrentTimeUs() noexcept;                            // 0x023bf0
    static bool IsLittleEndian() noexcept;                                 // 0x023c18
    static int32_t GetSystemVersion() noexcept;                            // 0x023c1c
    static std::string GetDeviceModel();                                   // 0x023c64
    static std::string GetSystemProperty(std::string key);                 // 0x023cf4
    static int32_t GetSystemPropertyInt(std::string key);                  // 0x023d6c
    static bool IsSupportHardwareBuffer() noexcept;                        // 0x023dc4
    static int16_t ClipInt16(int32_t val) noexcept;                        // 0x023de0
    static uint64_t MoveLeftInt64(uint64_t val, int32_t shift) noexcept;   // 0x023df4
    static uint64_t MoveRightInt64(uint64_t val, int32_t shift) noexcept;  // 0x023e2c
    static void Int64ToByteArray(const uint64_t& val, uint8_t* out) noexcept; // 0x023e68
    static void IntToByteArray(const uint32_t& val, uint8_t* out) noexcept;   // 0x023e8c
    static void ByteArrayToInt64(uint8_t* bytes, int64_t& out) noexcept;   // 0x023eb0
    static void ByteArrayToInt(uint8_t* bytes, int32_t& out) noexcept;     // 0x023ee4
    static std::string Pointer2String(void* ptr);                          // 0x023f18
    static std::string readDataFromFile(std::string& path);                // 0x024044
};

uint32_t SimulateTtrFdeEntry(uint32_t fde_index, uint32_t arg0, uint32_t arg1) noexcept;

} // namespace ttr_render

bool glstubInit(bool prefer_gles3) noexcept; // 0x03209c
void glstubDestroy() noexcept;               // 0x035880
