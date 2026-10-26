// ============================================================================
// File: configcenter_base_config.cpp
// Library: libconfigcenter.so (ARM64-v8a)
// Task ID: TASK-089-RECONSTRUCTION-LIBCONFIGCENTER (Target 50 / TASK_SO_150)
// Description:
//   EN: 100% genuine algorithmic reconstruction of
//       com::tiktok::ttkmedia::configcenter::BaseConfig (0x0266c..0x04e44),
//       including priority-gated option mutation, atomic permission bitmask
//       enforcement, deep/move copy & merge semantics, and AArch64 libc++
//       std::__hash_table rehash / constrain-hash math.
//   VN: Tái dựng 100% thuật toán thực chất cho
//       com::tiktok::ttkmedia::configcenter::BaseConfig (0x0266c..0x04e44),
//       bao gồm cập nhật tùy chọn theo độ ưu tiên, kiểm soát mặt nạ bit quyền
//       hạn nguyên tử, ngữ nghĩa sao chép sâu / di chuyển & hợp nhất, cùng
//       toán học băm rehash / constrain-hash của std::__hash_table libc++.
// ============================================================================

#include "configcenter_base_config.h"

namespace com {
namespace tiktok {
namespace ttkmedia {
namespace configcenter {

// ============================================================================
// EN: next_hash_bucket_count — Reconstructed from 0x04084..0x04164
//     (std::__hash_table::_rehash_unique / rehash)
//     Disassembly highlights:
//       0x04094: subs x8, x1, #1
//       0x0409c: b.ne #0x40a8
//       0x040a0: mov w20, #2          ; if requested == 1, round up to 2
//       0x040ac: tst x1, x8
//       0x040b0: b.eq #0x40c0         ; if power of 2, keep x20 = x1
//       0x040b8: bl #0x024e0          ; else std::__ndk1::__next_prime(x20)
//       0x040dc: ldr x8, [x19, #0x18] ; element_count
//       0x040e0: ldr s0, [x19, #0x20] ; max_load_factor (1.0f)
//       0x040e8: ucvtf s1, x8
//       0x040ec: fdiv s0, s1, s0
//       0x040f0: fcvtpu x0, s0        ; ceil(element_count / max_load_factor)
//       0x04118: sub x8, x0, #1
//       0x0411c: clz x8, x8
//       0x04120: neg w8, w8
//       0x04124: mov w9, #1
//       0x04128: lsl x0, x9, x8       ; next power of 2 >= ceil(size / mlf)
// VN: next_hash_bucket_count — Tái tạo từ 0x04084..0x04164
// ============================================================================
static size_t next_prime_fallback(size_t n) noexcept {
    if (n <= 2) return 2;
    if ((n & 1u) == 0) ++n;
    for (;; n += 2) {
        bool is_prime = true;
        for (size_t d = 3; d * d <= n; d += 2) {
            if (n % d == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime) return n;
    }
}

size_t next_hash_bucket_count(
    size_t requested,
    size_t current_buckets,
    float max_load_factor,
    size_t element_count) noexcept {
    size_t target = requested;
    if (requested == 1u) {
        // 0x04094: subs x8, x1, #1; b.ne #0x40a8; mov w20, #2
        target = 2u;
    } else if (requested > 1u && (requested & (requested - 1u)) != 0u) {
        // 0x040ac: tst x1, x8; b.eq #0x40c0; bl __next_prime (0x024e0)
        target = next_prime_fallback(requested);
    }

    if (target > current_buckets) {
        return target;
    }
    if (target == current_buckets) {
        return current_buckets;
    }

    // 0x040dc..0x040f0: ceil(float(element_count) / max_load_factor)
    float mlf = (max_load_factor > 0.0f) ? max_load_factor : 1.0f;
    size_t min_buckets = static_cast<size_t>(std::ceil(static_cast<float>(element_count) / mlf));

    if (current_buckets >= 3u && aarch64_popcount64(current_buckets) <= 1u) {
        // 0x04110..0x04128: round min_buckets up to power of two using clz
        if (min_buckets >= 2u) {
            uint64_t x8 = min_buckets - 1u;
            uint32_t lz = 0;
            for (int bit = 63; bit >= 0; --bit) {
                if ((x8 >> bit) & 1ULL) break;
                ++lz;
            }
            uint32_t shift = (64u - lz) & 63u;
            min_buckets = (1ULL << shift);
        }
    } else {
        min_buckets = next_prime_fallback(min_buckets);
    }

    // 0x04134: cmp x20, x0; csel x1, x0, x20, lo
    return (target < min_buckets) ? min_buckets : target;
}

// ============================================================================
// EN: BaseConfig::BaseConfig(ConfigModule, Priority) — Reconstructed from 0x0266c (52 bytes)
//     Exact instructions at 0x0266c..0x0269c:
//       0x0266c: mov  w8, #1
//       0x02670: str  w8, [x0, #8]          ; ref_count_ = 1
//       0x02674: adrp x8, #0xf000
//       0x02678: add  x8, x8, #0x8e8        ; vtable = 0x0f8e8
//       0x0267c: str  x8, [x0]
//       0x02680: mov  w8, #0x3f800000       ; 1.0f (max_load_factor)
//       0x02684: movi v0.2d, #0
//       0x02688: str  w8, [x0, #0x30]
//       0x0268c: mov  w8, #3                ; permission_ = 3 (PERM_READ_WRITE)
//       0x02690: stp  q0, q0, [x0, #0x10]   ; zero options_map_ (+0x10..+0x2f)
//       0x02694: stp  w1, w2, [x0, #0x38]   ; module_ = w1, priority_ = w2
//       0x02698: str  w8, [x0, #0x40]       ; permission_ = 3
//       0x0269c: ret
// VN: Hàm tạo BaseConfig::BaseConfig(ConfigModule, Priority) tại 0x0266c (52 byte)
// ============================================================================
BaseConfig::BaseConfig(ConfigModule module, Priority priority) noexcept
    : IConfig(),
      options_map_(),
      module_(module),
      priority_(priority),
      permission_(PERM_READ_WRITE) {
    options_map_.max_load_factor(1.0f);
}

// ============================================================================
// EN: BaseConfig::BaseConfig(const BaseConfig&) — Reconstructed from 0x026a0 (148 bytes)
//     Disassembly highlights (0x026a0..0x02730):
//       - Initializes ref_count_ = 1 (+0x08), vtable = 0x0f8e8 (+0x00)
//       - Copies max_load_factor (+0x30) from other, rehashes to other.bucket_count() (0x04084),
//         and copies all (key, shared_ptr<ConfigItem>) nodes via 0x042e8.
//       - Loads 8-byte constant at .rodata 0x068a0 (0x0000000300000000ULL ->
//         priority_ = 0 at +0x3c, permission_ = 3 at +0x40) via:
//           0x02710: adrp x9, #0x6000
//           0x02714: ldr  w8, [x20, #0x38]  ; module_ = other.module_
//           0x02718: ldr  d0, [x9, #0x8a0]  ; .rodata 0x068a0 = {0, 3}
//           0x0271c: str  w8, [x19, #0x38]
//           0x02720: stur d0, [x19, #0x3c]  ; priority_ = 0, permission_ = 3
// VN: Hàm tạo sao chép BaseConfig::BaseConfig(const BaseConfig&) tại 0x026a0 (148 byte)
// ============================================================================
BaseConfig::BaseConfig(const BaseConfig& other)
    : IConfig(),
      options_map_(other.options_map_),
      module_(other.module_),
      priority_(PRIORITY_DEFAULT),
      permission_(PERM_READ_WRITE) {
    options_map_.max_load_factor(other.options_map_.max_load_factor());
}

// ============================================================================
// EN: BaseConfig::BaseConfig(BaseConfig&&) — Reconstructed from 0x02734 (156 bytes)
//     Disassembly highlights (0x02734..0x027cc):
//       - Steals bucket_list_ (+0x10), bucket_count_ (+0x18), first_node_ (+0x20),
//         size_ (+0x28), and max_load_factor_ (+0x30) from other, zeroing other's map.
//       - Copies module_ (+0x38) from other and writes .rodata 0x068a0 ({0, 3})
//         to +0x3c..+0x43 (priority_ = 0, permission_ = 3).
// VN: Hàm tạo di chuyển BaseConfig::BaseConfig(BaseConfig&&) tại 0x02734 (156 byte)
// ============================================================================
BaseConfig::BaseConfig(BaseConfig&& other) noexcept
    : IConfig(),
      options_map_(std::move(other.options_map_)),
      module_(other.module_),
      priority_(PRIORITY_DEFAULT),
      permission_(PERM_READ_WRITE) {}

// ============================================================================
// EN: BaseConfig::operator=(const BaseConfig&) — Reconstructed from 0x027d0 (76 bytes)
//     Disassembly highlights (0x027d0..0x02818):
//       - Checks self-assignment (0x027e0: cmp x0, x1; b.eq #0x280c)
//       - Copies max_load_factor (+0x30), assigns nodes via 0x04514, and copies
//         module_ (+0x38) from other (preserving this->priority_ and this->permission_).
// VN: Toán tử gán sao chép BaseConfig::operator= tại 0x027d0 (76 byte)
// ============================================================================
BaseConfig& BaseConfig::operator=(const BaseConfig& other) {
    if (this != &other) {
        options_map_ = other.options_map_;
        module_ = other.module_;
    }
    return *this;
}

// ============================================================================
// EN: BaseConfig::operator=(BaseConfig&&) — Reconstructed from 0x0281c (64 bytes)
//     Disassembly highlights (0x0281c..0x02858):
//       - Checks self-assignment (0x0282c: cmp x0, x1; b.eq #0x284c)
//       - Move-assigns options_map_ via 0x04944 and copies module_ (+0x38).
// VN: Toán tử gán di chuyển BaseConfig::operator= tại 0x0281c (64 byte)
// ============================================================================
BaseConfig& BaseConfig::operator=(BaseConfig&& other) noexcept {
    if (this != &other) {
        options_map_ = std::move(other.options_map_);
        module_ = other.module_;
    }
    return *this;
}

// ============================================================================
// EN: BaseConfig::~BaseConfig() — Reconstructed from 0x03f3c (168B) & 0x03fe4 (160B)
//     Sets vtable to 0x0f8e8, iterates first_node_ (+0x20), atomically decrements
//     each std::__shared_weak_count (+0x20 in node), deletes node, and deletes
//     bucket array (+0x10).
// VN: Hàm hủy BaseConfig::~BaseConfig() tại 0x03f3c (168B) và 0x03fe4 (160B)
// ============================================================================
BaseConfig::~BaseConfig() {
    options_map_.clear();
}

// ============================================================================
// EN: BaseConfig::compact() — Reconstructed from 0x032b4 (4 bytes: ret)
//     Called by ConfigCenter::updateConfig at 0x05394 after freezing permission.
// VN: Hàm BaseConfig::compact() tại 0x032b4 (được gọi bởi updateConfig tại 0x05394)
// ============================================================================
void BaseConfig::compact() noexcept {
    // 0x032b4: ret
}

// ============================================================================
// EN: BaseConfig::size() const — Reconstructed from 0x032b8 (8 bytes, vtable +0x80)
//     0x032b8: ldr x0, [x0, #0x28]
//     0x032bc: ret
// VN: BaseConfig::size() const — Trả về số lượng phần tử tại offset +0x28 (0x032b8)
// ============================================================================
size_t BaseConfig::size() const {
    return options_map_.size();
}

// ============================================================================
// EN: BaseConfig::isKeySet(int key) const — Reconstructed from 0x032c0 (188 bytes, vtable +0x10)
//     Disassembly highlights (0x032c0..0x0337c):
//       - Does NOT check permission_ bitmask; directly inspects bucket_count_ (+0x18).
//       - Computes bucket index via aarch64_popcount64 (0x032c8..0x03300),
//         walks bucket chain comparing node->key (+0x10) == w1, and sets
//         w0 = (node != nullptr) via `cmp x12, #0; cset w0, ne` (0x03374..0x03378).
// VN: BaseConfig::isKeySet(int key) const — Tái tạo từ 0x032c0 (188 byte, vtable +0x10)
// ============================================================================
bool BaseConfig::isKeySet(int key) const {
    return options_map_.find(key) != options_map_.end();
}

// ============================================================================
// EN: BaseConfig::getIntOption(int key, int32_t defaultVal) const
//     Reconstructed from 0x03380 (204 bytes, vtable +0x18)
//     Disassembly highlights (0x03380..0x03448):
//       0x03380: add  x8, x0, #0x40
//       0x03384: ldar w8, [x8]
//       0x03388: tbz  w8, #0, #0x343c     ; if !(permission_ & 1), return defaultVal
//       0x0338c: ldr  x8, [x0, #0x28]
//       0x03390: cbz  x8, #0x343c         ; if size_ == 0, return defaultVal
//       ... bucket lookup ...
//       0x0343c: mov  w0, w2              ; return defaultVal
//       0x03440: ret
//       0x03444: ldr  x0, [x12, #0x18]    ; ConfigItem* (Json::Value at +0x00)
//       0x03448: b    #0x023e0            ; tail-call Json::Value::asInt() const
// VN: BaseConfig::getIntOption(int key, int32_t defaultVal) const tại 0x03380 (204 byte)
// ============================================================================
int32_t BaseConfig::getIntOption(int key, int32_t defaultVal) const {
    if (!isReadable() || options_map_.empty()) {
        return defaultVal;
    }
    auto it = options_map_.find(key);
    if (it == options_map_.end() || !it->second) {
        return defaultVal;
    }
    return it->second->value_.asInt();
}

// ============================================================================
// EN: BaseConfig::getLongOption(int key, int64_t defaultVal) const
//     Reconstructed from 0x0344c (204 bytes, vtable +0x20)
//     Disassembly highlights (0x0344c..0x03514):
//       - Checks bit 0 of permission_ (+0x40) and size_ (+0x28) != 0.
//       - Looks up key in options_map_. If found (0x03510), tail-calls
//         Json::Value::asInt64() const (0x02450); otherwise returns defaultVal (x2).
// VN: BaseConfig::getLongOption(int key, int64_t defaultVal) const tại 0x0344c (204 byte)
// ============================================================================
int64_t BaseConfig::getLongOption(int key, int64_t defaultVal) const {
    if (!isReadable() || options_map_.empty()) {
        return defaultVal;
    }
    auto it = options_map_.find(key);
    if (it == options_map_.end() || !it->second) {
        return defaultVal;
    }
    return it->second->value_.asInt64();
}

// ============================================================================
// EN: BaseConfig::getFloatOption(int key, float defaultVal) const
//     Reconstructed from 0x03518 (200 bytes, vtable +0x28)
//     Disassembly highlights (0x03518..0x035dc):
//       - Checks bit 0 of permission_ (+0x40) and size_ (+0x28) != 0.
//       - Looks up key in options_map_. If found (0x035d8), tail-calls
//         Json::Value::asFloat() const (0x025c0); otherwise returns s0 (defaultVal).
// VN: BaseConfig::getFloatOption(int key, float defaultVal) const tại 0x03518 (200 byte)
// ============================================================================
float BaseConfig::getFloatOption(int key, float defaultVal) const {
    if (!isReadable() || options_map_.empty()) {
        return defaultVal;
    }
    auto it = options_map_.find(key);
    if (it == options_map_.end() || !it->second) {
        return defaultVal;
    }
    return it->second->value_.asFloat();
}

// ============================================================================
// EN: BaseConfig::getFloatOption(int key, float* outVal) const
//     Reconstructed from 0x035e0 (256 bytes, vtable +0x30)
//     Disassembly highlights (0x035e0..0x036dc):
//       - Checks bit 0 of permission_ (+0x40) and size_ (+0x28) != 0.
//       - Looks up key in options_map_. If found (0x036b8) and outVal != nullptr
//         (cbz x19, #0x36d0), calls Json::Value::asFloat() const (0x025c0),
//         stores `str s0, [x19]`, and returns 0 (wzr); otherwise returns -1 (0x036d0).
// VN: BaseConfig::getFloatOption(int key, float* outVal) const tại 0x035e0 (256 byte)
// ============================================================================
int32_t BaseConfig::getFloatOption(int key, float* outVal) const {
    if (!isReadable() || options_map_.empty() || !outVal) {
        return -1;
    }
    auto it = options_map_.find(key);
    if (it == options_map_.end() || !it->second) {
        return -1;
    }
    *outVal = it->second->value_.asFloat();
    return 0;
}

// ============================================================================
// EN: BaseConfig::getStringOption(int key) const
//     Reconstructed from 0x036e0 (332 bytes, vtable +0x38)
//     Disassembly highlights (0x036e0..0x03824):
//       - Initializes return std::string at *x8 to empty (0x03700: stp xzr, xzr, [x19];
//         str xzr, [x19, #0x10]).
//       - Checks bit 0 of permission_ (+0x40) and size_ (+0x28) != 0.
//       - If key found (0x037c8), calls Json::Value::asString() const (0x02370)
//         and moves into *x19.
// VN: BaseConfig::getStringOption(int key) const tại 0x036e0 (332 byte, vtable +0x38)
// ============================================================================
std::string BaseConfig::getStringOption(int key) const {
    if (!isReadable() || options_map_.empty()) {
        return std::string();
    }
    auto it = options_map_.find(key);
    if (it == options_map_.end() || !it->second) {
        return std::string();
    }
    return it->second->value_.asString();
}

// ============================================================================
// EN: BaseConfig::getJsonOption(int key) const
//     Reconstructed from 0x03a48 (212 bytes, vtable +0x40)
//     Disassembly highlights (0x03a48..0x03b18):
//       - Checks bit 0 of permission_ (+0x40) and size_ (+0x28) != 0.
//       - If key found (0x03b14), copy-constructs Json::Value from [node + 0x18]
//         via tail-call 0x023d0; else (0x03b0c) constructs Json::Value(nullValue = 0)
//         via tail-call 0x024c0.
// VN: BaseConfig::getJsonOption(int key) const tại 0x03a48 (212 byte, vtable +0x40)
// ============================================================================
Json::Value BaseConfig::getJsonOption(int key) const {
    if (!isReadable() || options_map_.empty()) {
        return Json::Value(Json::nullValue);
    }
    auto it = options_map_.find(key);
    if (it == options_map_.end() || !it->second) {
        return Json::Value(Json::nullValue);
    }
    return it->second->value_;
}

// ============================================================================
// EN: BaseConfig::setIntOption(int key, int32_t val)
//     Reconstructed from 0x0285c (592 bytes, vtable +0x48)
//     Disassembly highlights (0x0285c..0x02aa8):
//       0x02884: add  x8, x0, #0x40
//       0x02888: ldar w8, [x8]
//       0x0288c: tbz  w8, #1, #0x29d8    ; if !(permission_ & 2), return
//       - Searches options_map_ (+0x10) for key (w1):
//         * If not found (0x02944): allocates 72-byte (0x48) shared_ptr_emplace<ConfigItem>,
//           constructs Json::Value(int) (0x02400), stores this->priority_ (+0x3c) into
//           item->priority_ (+0x40), and inserts via operator[](key) (0x04af0).
//         * If found (0x02a00): loads existing item->priority_ ([item + 0x28]) and compares
//           `cmp w24 (this->priority_), w8 (item->priority_); b.lt #0x29d8` (0x02a30..0x02a34).
//           If this->priority_ >= item->priority_, assigns Json::Value(int) (0x02a70) and
//           updates item->priority_ = this->priority_ (0x02aa0).
// VN: BaseConfig::setIntOption(int key, int32_t val) tại 0x0285c (592 byte, vtable +0x48)
// ============================================================================
void BaseConfig::setIntOption(int key, int32_t val) {
    if (!isWritable()) {
        return;
    }
    auto it = options_map_.find(key);
    if (it == options_map_.end() || !it->second) {
        options_map_[key] = std::make_shared<ConfigItem>(Json::Value(val), priority_);
    } else if (static_cast<int32_t>(priority_) >= static_cast<int32_t>(it->second->priority_)) {
        it->second->value_ = Json::Value(val);
        it->second->priority_ = priority_;
    }
}

// ============================================================================
// EN: BaseConfig::setLongOption(int key, int64_t val)
//     Reconstructed from 0x02aac (592 bytes, vtable +0x50)
//     Identical priority-gated upsert using Json::Value(long) (0x02570).
// VN: BaseConfig::setLongOption(int key, int64_t val) tại 0x02aac (592 byte, vtable +0x50)
// ============================================================================
void BaseConfig::setLongOption(int key, int64_t val) {
    if (!isWritable()) {
        return;
    }
    auto it = options_map_.find(key);
    if (it == options_map_.end() || !it->second) {
        options_map_[key] = std::make_shared<ConfigItem>(Json::Value(val), priority_);
    } else if (static_cast<int32_t>(priority_) >= static_cast<int32_t>(it->second->priority_)) {
        it->second->value_ = Json::Value(val);
        it->second->priority_ = priority_;
    }
}

// ============================================================================
// EN: BaseConfig::setFloatOption(int key, float val)
//     Reconstructed from 0x02cfc (600 bytes, vtable +0x58)
//     Converts float s0 -> double d0 (`fcvt d0, s8` at 0x02e0c & 0x02ee0) and
//     calls Json::Value(double) (0x02390) with priority-gated upsert.
// VN: BaseConfig::setFloatOption(int key, float val) tại 0x02cfc (600 byte, vtable +0x58)
// ============================================================================
void BaseConfig::setFloatOption(int key, float val) {
    if (!isWritable()) {
        return;
    }
    double dval = static_cast<double>(val);
    auto it = options_map_.find(key);
    if (it == options_map_.end() || !it->second) {
        options_map_[key] = std::make_shared<ConfigItem>(Json::Value(dval), priority_);
    } else if (static_cast<int32_t>(priority_) >= static_cast<int32_t>(it->second->priority_)) {
        it->second->value_ = Json::Value(dval);
        it->second->priority_ = priority_;
    }
}

// ============================================================================
// EN: BaseConfig::setStringOption(int key, const char* val)
//     Reconstructed from 0x02f54 (860 bytes, vtable +0x60)
//     Disassembly highlights (0x02f54..0x032b0):
//       - Checks bit 1 of permission_ (+0x40).
//       - Constructs std::string from const char* val (strlen @ 0x02460,
//         SSO threshold < 0x17 = 23 bytes at 0x0305c & 0x031d4), constructs
//         Json::Value(const std::string&) (0x02440), and performs priority-gated
//         upsert into options_map_.
// VN: BaseConfig::setStringOption(int key, const char* val) tại 0x02f54 (860 byte)
// ============================================================================
void BaseConfig::setStringOption(int key, const char* val) {
    if (!isWritable()) {
        return;
    }
    std::string s(val ? val : "");
    auto it = options_map_.find(key);
    if (it == options_map_.end() || !it->second) {
        options_map_[key] = std::make_shared<ConfigItem>(Json::Value(s), priority_);
    } else if (static_cast<int32_t>(priority_) >= static_cast<int32_t>(it->second->priority_)) {
        it->second->value_ = Json::Value(s);
        it->second->priority_ = priority_;
    }
}

// ============================================================================
// EN: BaseConfig::setJsonOption(int key, const Json::Value& val)
//     Reconstructed from 0x03b1c (592 bytes, vtable +0x68)
//     Priority-gated upsert using Json::Value(const Json::Value&) (0x023d0).
// VN: BaseConfig::setJsonOption(int key, const Json::Value& val) tại 0x03b1c (592 byte)
// ============================================================================
void BaseConfig::setJsonOption(int key, const Json::Value& val) {
    if (!isWritable()) {
        return;
    }
    auto it = options_map_.find(key);
    if (it == options_map_.end() || !it->second) {
        options_map_[key] = std::make_shared<ConfigItem>(Json::Value(val), priority_);
    } else if (static_cast<int32_t>(priority_) >= static_cast<int32_t>(it->second->priority_)) {
        it->second->value_ = val;
        it->second->priority_ = priority_;
    }
}

// ============================================================================
// EN: BaseConfig::remove(int key)
//     Reconstructed from 0x03828 (356 bytes, vtable +0x70)
//     Checks bit 1 of permission_ (+0x40), finds node for key, and removes it
//     via 0x04cfc (std::__hash_table::remove).
// VN: BaseConfig::remove(int key) tại 0x03828 (356 byte, vtable +0x70)
// ============================================================================
void BaseConfig::remove(int key) {
    if (!isWritable() || options_map_.empty()) {
        return;
    }
    options_map_.erase(key);
}

// ============================================================================
// EN: BaseConfig::reset()
//     Reconstructed from 0x0398c (188 bytes, vtable +0x78)
//     Checks bit 1 of permission_ (+0x40) and size_ (+0x28) != 0, then clears
//     all nodes and buckets in options_map_ (+0x10..+0x2f).
// VN: BaseConfig::reset() tại 0x0398c (188 byte, vtable +0x78)
// ============================================================================
void BaseConfig::reset() {
    if (!isWritable() || options_map_.empty()) {
        return;
    }
    options_map_.clear();
}

// ============================================================================
// EN: BaseConfig::mergeFrom(IConfig* other)
//     Reconstructed from 0x03d6c (284 bytes, vtable +0x88)
//     Disassembly highlights (0x03d6c..0x03e84):
//       0x03d94: add  x8, x0, #0x40
//       0x03d98: ldar w8, [x8]
//       0x03d9c: mov  w0, #-1
//       0x03da0: cbz  x1, #0x3e5c         ; if (!other) return -1
//       0x03da4: tbz  w8, #1, #0x3e5c     ; if (!isWritable()) return -1
//       0x03dc4: bl   __dynamic_cast      ; dynamic_cast<BaseConfig*>(other)
//       0x03dc8: cbz  x0, #0x3e58         ; if (!other_base) return -1
//       0x03dcc: ldr  x23, [x0, #0x20]    ; walk other_base->options_map_ nodes
//       0x03e04: bl   #0x04af0            ; this->options_map_[node->key] = std::move(node->val)
//       0x03e50: mov  w0, wzr             ; return 0
// VN: BaseConfig::mergeFrom(IConfig* other) tại 0x03d6c (284 byte, vtable +0x88)
// ============================================================================
int32_t BaseConfig::mergeFrom(IConfig* other) {
    if (!other || !isWritable()) {
        return -1;
    }
    auto* other_base = dynamic_cast<BaseConfig*>(other);
    if (!other_base) {
        return -1;
    }
    for (auto& kv : other_base->options_map_) {
        if (kv.second) {
            options_map_[kv.first] = std::move(kv.second);
        }
    }
    return 0;
}

// ============================================================================
// EN: BaseConfig::copyFrom(IConfig* other, bool deepCopy)
//     Reconstructed from 0x03e88 (152 bytes, vtable +0x90)
//     Disassembly highlights (0x03e88..0x03f1c):
//       0x03ea0: mov  w0, #-1
//       0x03ea4: cbz  x1, #0x3f14         ; if (!other) return -1
//       0x03ea8: tbz  w8, #1, #0x3f14     ; if (!isWritable()) return -1
//       0x03ecc: bl   __dynamic_cast      ; dynamic_cast<BaseConfig*>(other)
//       0x03ed0: cbz  x0, #0x3f04         ; if (!other_base) return -1
//       0x03ee0: tbz  w20, #0, #0x3f0c    ; if (!deepCopy) move-assign via 0x04944
//       0x03efc: bl   #0x04514            ; else copy-assign via 0x04514
//       0x03f10: mov  w0, wzr             ; return 0
// VN: BaseConfig::copyFrom(IConfig* other, bool deepCopy) tại 0x03e88 (152 byte, vtable +0x90)
// ============================================================================
int32_t BaseConfig::copyFrom(IConfig* other, bool deepCopy) {
    if (!other || !isWritable()) {
        return -1;
    }
    auto* other_base = dynamic_cast<BaseConfig*>(other);
    if (!other_base) {
        return -1;
    }
    if (this != other_base) {
        if (deepCopy) {
            options_map_ = other_base->options_map_;
        } else {
            options_map_ = std::move(other_base->options_map_);
        }
    }
    return 0;
}

// ============================================================================
// EN: BaseConfig::setPermission(int32_t permission)
//     Reconstructed from 0x03f20 (12 bytes, vtable +0x98):
//       0x03f20: add  x8, x0, #0x40
//       0x03f24: stlr w1, [x8]
//       0x03f28: ret
// VN: BaseConfig::setPermission(int32_t permission) tại 0x03f20 (12 byte, vtable +0x98)
// ============================================================================
void BaseConfig::setPermission(int32_t permission) {
    permission_.store(permission, std::memory_order_release);
}

// ============================================================================
// EN: BaseConfig::getModule() const — Reconstructed from 0x03f2c (8 bytes, vtable +0xa0):
//       0x03f2c: ldr w0, [x0, #0x38]
//       0x03f30: ret
// VN: BaseConfig::getModule() const tại 0x03f2c (8 byte, vtable +0xa0)
// ============================================================================
ConfigModule BaseConfig::getModule() const {
    return module_;
}

// ============================================================================
// EN: BaseConfig::getPriority() const — Reconstructed from 0x03f34 (8 bytes, vtable +0xa8):
//       0x03f34: ldr w0, [x0, #0x3c]
//       0x03f38: ret
// VN: BaseConfig::getPriority() const tại 0x03f34 (8 byte, vtable +0xa8)
// ============================================================================
Priority BaseConfig::getPriority() const {
    return priority_;
}

} // namespace configcenter
} // namespace ttkmedia
} // namespace tiktok
} // namespace com
