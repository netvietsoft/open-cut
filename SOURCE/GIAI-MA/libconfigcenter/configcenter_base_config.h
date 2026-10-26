// ============================================================================
// File: configcenter_base_config.h
// Library: libconfigcenter.so (ARM64-v8a)
// Task ID: TASK-089-RECONSTRUCTION-LIBCONFIGCENTER (Target 50 / TASK_SO_150)
// Description:
//   EN: Declaration of com::tiktok::ttkmedia::configcenter::BaseConfig
//       (72 bytes = 0x48, vtable @ 0x0f8e8) and the exact AArch64 libc++
//       std::__hash_table bucket-indexing & power-of-two population-count
//       algorithms (0x0266c..0x04e44).
//   VN: Khai báo lớp com::tiktok::ttkmedia::configcenter::BaseConfig
//       (72 byte = 0x48, vtable @ 0x0f8e8) và các thuật toán chỉ mục bucket
//       kèm đếm bit lũy thừa của 2 chuẩn libc++ AArch64 (0x0266c..0x04e44).
// ============================================================================

#pragma once

#include "configcenter_types.h"

namespace com {
namespace tiktok {
namespace ttkmedia {
namespace configcenter {

// ============================================================================
// EN: Exact AArch64 libc++ std::__hash_table bucket index computation
//     Reconstructed from 0x028a4..0x028dc, 0x032c8..0x03300, 0x0339c..0x033d4,
//     0x040f8..0x0412c, 0x041cc..0x04218, 0x04860..0x04894, 0x04d04..0x04d34:
//       fmov d0, x8              ; x8 = bucket_count (ch)
//       cnt  v0.8b, v0.8b        ; byte-wise popcount
//       uaddlv h0, v0.8b         ; sum popcounts across 8 bytes -> popcount64(ch)
//       fmov w10, s0
//       cmp  x10, #1
//       b.ls power_of_two_path   ; if popcount(ch) <= 1, index = hash & (ch - 1)
//       udiv x11, hash, ch       ; else index = hash - (hash / ch) * ch
//       msub x11, x11, ch, hash
// VN: Tính toán chỉ số bucket của std::__hash_table libc++ trên AArch64:
//     Nếu số lượng bit 1 của bucket_count <= 1 (lũy thừa của 2), dùng phép AND
//     nhị phân `hash & (bucket_count - 1)`; ngược lại dùng `udiv` + `msub`.
// ============================================================================
inline uint32_t aarch64_popcount64(uint64_t val) noexcept {
    // Exact software model of: fmov d0, x8; cnt v0.8b, v0.8b; uaddlv h0, v0.8b
    uint32_t sum = 0;
    for (int i = 0; i < 8; ++i) {
        uint8_t byte_val = static_cast<uint8_t>((val >> (i * 8)) & 0xFFu);
        uint8_t b = byte_val;
        b = static_cast<uint8_t>((b & 0x55u) + ((b >> 1) & 0x55u));
        b = static_cast<uint8_t>((b & 0x33u) + ((b >> 2) & 0x33u));
        b = static_cast<uint8_t>((b & 0x0Fu) + ((b >> 4) & 0x0Fu));
        sum += b;
    }
    return sum;
}

inline size_t compute_constrain_hash(size_t hash, size_t bucket_count) noexcept {
    if (bucket_count == 0) {
        return 0;
    }
    uint32_t popcnt = aarch64_popcount64(bucket_count);
    if (popcnt <= 1u) {
        // 0x028d8: sub x11, x8, #1; and x11, x11, x9
        return hash & (bucket_count - 1u);
    }
    // 0x028c0: cmp x8, x9; b.hi #0x028e0; udiv x11, x9, x8; msub x11, x11, x8, x9
    if (bucket_count > hash) {
        return hash;
    }
    size_t q = hash / bucket_count;
    return hash - q * bucket_count;
}

// ============================================================================
// EN: Next power-of-two / prime helper used by std::__hash_table::rehash (0x04084)
//     At 0x04110..0x04128:
//       cmp x0, #2
//       b.lo #0x4134
//       sub x8, x0, #1
//       clz x8, x8
//       neg w8, w8
//       mov w9, #1
//       lsl x0, x9, x8   ; (1ULL << ((64 - clz(x0 - 1)) & 63))
// VN: Hàm tính lũy thừa của 2 kế tiếp hoặc số nguyên tố kế tiếp trong rehash (0x04084)
// ============================================================================
size_t next_hash_bucket_count(size_t requested, size_t current_buckets, float max_load_factor, size_t element_count) noexcept;

// ============================================================================
// EN: BaseConfig (72 bytes = 0x48, vtable @ .data.rel.ro 0x0f8e8)
//     Exact member layout verified from 0x0266c..0x02858:
//       +0x00: vtable* (8B, points to 0x0f8e8)
//       +0x08: std::atomic<int32_t> ref_count_ (4B, init = 1) + 4B pad
//       +0x10..+0x37: std::unordered_map<int, std::shared_ptr<ConfigItem>> options_map_ (40B)
//         * +0x10: bucket_list_
//         * +0x18: bucket_count_
//         * +0x20: first_node_
//         * +0x28: size_ (returned by size() @ 0x032b8)
//         * +0x30: max_load_factor_ (float = 1.0f = 0x3f800000 @ 0x02680) + 4B pad
//       +0x38: ConfigModule module_ (int32_t, returned by getModule() @ 0x03f2c)
//       +0x3c: Priority priority_ (int32_t, returned by getPriority() @ 0x03f34)
//       +0x40: std::atomic<int32_t> permission_ (int32_t, init = 3 @ 0x0268c,
//              updated via stlr w1, [x0, #0x40] @ 0x03f20)
// VN: Lớp BaseConfig (72 byte = 0x48, vtable tại .data.rel.ro 0x0f8e8)
// ============================================================================
class BaseConfig : public IConfig {
public:
    // 0x0266c (52 bytes): BaseConfig(ConfigModule module, Priority priority)
    BaseConfig(ConfigModule module, Priority priority) noexcept;

    // 0x026a0 (148 bytes): BaseConfig(const BaseConfig& other)
    BaseConfig(const BaseConfig& other);

    // 0x02734 (156 bytes): BaseConfig(BaseConfig&& other) noexcept
    BaseConfig(BaseConfig&& other) noexcept;

    // 0x027d0 (76 bytes): BaseConfig& operator=(const BaseConfig& other)
    BaseConfig& operator=(const BaseConfig& other);

    // 0x0281c (64 bytes): BaseConfig& operator=(BaseConfig&& other) noexcept
    BaseConfig& operator=(BaseConfig&& other) noexcept;

    // 0x03f3c (168 bytes, D1) & 0x03fe4 (160 bytes, D0): ~BaseConfig()
    ~BaseConfig() override;

    // 20 Virtual Methods in vtable 0x0f8e8 (+0x10 .. +0xa8)
    bool isKeySet(int key) const override;                                    // 0x032c0 (+0x10)
    int32_t getIntOption(int key, int32_t defaultVal) const override;         // 0x03380 (+0x18)
    int64_t getLongOption(int key, int64_t defaultVal) const override;        // 0x0344c (+0x20)
    float getFloatOption(int key, float defaultVal) const override;           // 0x03518 (+0x28)
    int32_t getFloatOption(int key, float* outVal) const override;            // 0x035e0 (+0x30)
    std::string getStringOption(int key) const override;                      // 0x036e0 (+0x38)
    Json::Value getJsonOption(int key) const override;                        // 0x03a48 (+0x40)
    void setIntOption(int key, int32_t val) override;                         // 0x0285c (+0x48)
    void setLongOption(int key, int64_t val) override;                        // 0x02aac (+0x50)
    void setFloatOption(int key, float val) override;                         // 0x02cfc (+0x58)
    void setStringOption(int key, const char* val) override;                  // 0x02f54 (+0x60)
    void setJsonOption(int key, const Json::Value& val) override;             // 0x03b1c (+0x68)
    void remove(int key) override;                                            // 0x03828 (+0x70)
    void reset() override;                                                    // 0x0398c (+0x78)
    size_t size() const override;                                             // 0x032b8 (+0x80)
    int32_t mergeFrom(IConfig* other) override;                               // 0x03d6c (+0x88)
    int32_t copyFrom(IConfig* other, bool deepCopy) override;                 // 0x03e88 (+0x90)
    void setPermission(int32_t permission) override;                          // 0x03f20 (+0x98)
    ConfigModule getModule() const override;                                  // 0x03f2c (+0xa0)
    Priority getPriority() const override;                                    // 0x03f34 (+0xa8)

    // 0x032b4 (4 bytes): compact / finalize helper called by updateConfig @ 0x05394
    void compact() noexcept;

    int32_t getPermission() const noexcept {
        return permission_.load(std::memory_order_acquire);
    }

    const std::unordered_map<int, std::shared_ptr<ConfigItem>>& rawOptionsMap() const noexcept {
        return options_map_;
    }

private:
    bool isReadable() const noexcept {
        // Verified at 0x03384..0x03388: ldar w8, [x0, #0x40]; tbz w8, #0, skip
        return (permission_.load(std::memory_order_acquire) & PERM_READ_ONLY) != 0;
    }

    bool isWritable() const noexcept {
        // Verified at 0x02884..0x0288c: ldar w8, [x0, #0x40]; tbz w8, #1, skip
        return (permission_.load(std::memory_order_acquire) & PERM_WRITE_ONLY) != 0;
    }

private:
    std::unordered_map<int, std::shared_ptr<ConfigItem>> options_map_; // +0x10..+0x37
    ConfigModule module_;                                              // +0x38
    Priority priority_;                                                // +0x3c
    std::atomic<int32_t> permission_;                                  // +0x40
};

} // namespace configcenter
} // namespace ttkmedia
} // namespace tiktok
} // namespace com
