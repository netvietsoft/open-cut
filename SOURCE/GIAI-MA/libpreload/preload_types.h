// ============================================================================
// Clean-Room C++17 Type Definitions for libpreload.so (Target 121 / 169)
// Định nghĩa kiểu dữ liệu C++17 sạch cho libpreload.so (Mục tiêu 121 / 169)
// Binary: 3,657,488 bytes | SHA-256: 9f88e5ffe24e072d7ba2fb5a9bfe50378664a36db5998d0524574b8a238a11b9
// Architecture: AArch64 (ARM64-v8a) | .eh_frame_hdr: 8,944 FDEs @ 0x305cfc
// ============================================================================
#pragma once

#include <cstdint>
#include <cstddef>
#include <cstring>
#include <cmath>
#include <atomic>
#include <vector>
#include <string>
#include <functional>

namespace com {
namespace ss {
namespace vcbkit {

// Reconstructed from 0x29b8d8 (com::ss::vcbkit::BaseRef::~BaseRef)
// Tái dựng từ 0x29b8d8 (lớp cơ sở đếm tham chiếu BaseRef)
class BaseRef {
public:
    virtual ~BaseRef() noexcept {} // 0x29b8d8: D65F03C0 ret
    void retain() noexcept { ref_count_.fetch_add(1, std::memory_order_relaxed); }
    bool release() noexcept {
        return ref_count_.fetch_sub(1, std::memory_order_acq_rel) == 1;
    }
private:
    std::atomic<int32_t> ref_count_{1};
};

} // namespace vcbkit

namespace ttm {
namespace player {

// Reconstructed from 0x2919d4..0x291e80 (com::ss::ttm::player::Parcel)
// Tái dựng từ 0x2919d4..0x291e80 (bộ đóng gói tham số 32-byte mỗi phần tử của TTMPlayer)
struct ParcelEntry {
    int64_t i64_val{0};      // +0x00
    void* ptr_val{nullptr};  // +0x08
    const char* str_val{nullptr}; // +0x10
    uint64_t tag{0};         // +0x18 (sizeof == 0x20 = 32 bytes, asr #5 @ 0x291a40)
};

struct Parcel {
    uint64_t count_{0};          // +0x00 (incremented @ 0x291ad0..0x291ae8)
    ParcelEntry* begin_{nullptr}; // +0x08 (ldr x10, [x22, #8] @ 0x291a38)
    ParcelEntry* end_{nullptr};   // +0x10 (ldp x24, x8, [x0, #0x10] @ 0x291a0c)
    ParcelEntry* cap_{nullptr};   // +0x18 (capacity end pointer)
};

} // namespace player
} // namespace ttm
} // namespace ss

namespace tiktok {
namespace ttkmedia {
namespace configcenter {

// Reconstructed from 0x29f898 (IConfigCenterListener::~IConfigCenterListener)
// Tái dựng từ 0x29f898 (Giao diện lắng nghe cấu hình TTKMedia ConfigCenter)
class IConfigCenterListener {
public:
    virtual ~IConfigCenterListener() noexcept {} // 0x29f898: D65F03C0 ret
    virtual void onConfigUpdated(const char* group, const char* key) = 0;
};

} // namespace configcenter
} // namespace ttkmedia
} // namespace tiktok

namespace bd {
namespace vod {
namespace ST {

// Global Log Level Key checked in _setIntValue (0x27c190: mov w8, #0xc3bf = 50111)
// Mã khóa mức ghi nhật ký toàn cục kiểm tra trong _setIntValue (0x27c190: 50111 = 0xC3BF)
constexpr int32_t kStrategyLogLevelKey = 0xC3BF; // 50111

// StrategyCenter allocation size in _create (0x27b5f4: mov w0, #0x10d0 = 4,304 bytes)
// Kích thước cấp phát StrategyCenter trong _create (0x27b5f4: 4,304 bytes)
constexpr size_t kStrategyCenterStructSize = 0x10D0;

// Weibull Play-Time Estimation Parameters (.rodata 0x2bbb25: EstPlayTimeByWeibullParams)
// Tham số ước lượng thời gian phát theo phân phối Weibull (.rodata 0x2bbb25)
struct EstPlayTimeByWeibullParams {
    double shape_k{1.25};       // Tham số hình dạng k > 0 (Weibull shape)
    double scale_lambda{30.0};  // Tham số tỷ lệ lambda > 0 (Weibull scale in seconds)
    double max_duration_s{180.0}; // Thời lượng tối đa (giây)
    double threshold_prob{0.50};  // Ngưỡng xác suất giữ chân người xem
};

} // namespace ST
} // namespace vod
} // namespace bd
} // namespace com
