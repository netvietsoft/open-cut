// ============================================================================
// Clean-Room C++17 Core Implementation for libavmdlv2.so (Target 114 / 169)
// Hiện thực C++17 sạch lõi cho libavmdlv2.so (MDLMessage, MDLSingletonsHolder, ID)
// ============================================================================
#include "avmdlv2_core.h"
#include <cstring>
#include <sstream>
#include <iomanip>

namespace com {
namespace ss {
namespace ttmio {

// Reconstructed from 0x116640..0x116b08 (ID hex/BCD parser & comparator)
// Tái dựng từ 0x116640..0x116b08 (Bộ phân tích & so sánh ID hex/BCD)
ID::ID() noexcept {
    reset();
}

ID::ID(uint8_t* raw_bytes) noexcept {
    if (raw_bytes) {
        std::memcpy(buf_, raw_bytes, 16);
    } else {
        reset();
    }
}

ID::ID(const std::string& hex_str) {
    reset();
    parse(hex_str);
}

int32_t ID::ctoi(char c) noexcept {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'a' && c <= 'f') return c - 'a' + 10;
    if (c >= 'A' && c <= 'F') return c - 'A' + 10;
    return 0;
}

bool ID::parse(const std::string& hex_str) {
    if (hex_str.size() < 32) {
        return false;
    }
    for (size_t i = 0; i < 16; ++i) {
        buf_[i] = static_cast<uint8_t>((ctoi(hex_str[2 * i]) << 4) | ctoi(hex_str[2 * i + 1]));
    }
    return true;
}

void ID::BCDtoASCII(const uint8_t* bcd, int32_t len, char* out_ascii) noexcept {
    static const char kHexDigits[] = "0123456789abcdef";
    if (!bcd || !out_ascii || len <= 0) return;
    for (int32_t i = 0; i < len; ++i) {
        out_ascii[2 * i]     = kHexDigits[(bcd[i] >> 4) & 0x0F];
        out_ascii[2 * i + 1] = kHexDigits[bcd[i] & 0x0F];
    }
    out_ascii[2 * len] = '\0';
}

std::string ID::toStr() const {
    char out[33]{0};
    BCDtoASCII(buf_, 16, out);
    return std::string(out);
}

std::string ID::toLogStr() const {
    return toStr();
}

bool ID::isEmpty() const noexcept {
    for (uint8_t b : buf_) {
        if (b != 0) return false;
    }
    return true;
}

void ID::reset() noexcept {
    std::memset(buf_, 0, sizeof(buf_));
}

ID& ID::operator=(const ID& other) noexcept {
    if (this != &other) {
        std::memcpy(buf_, other.buf_, 16);
    }
    return *this;
}

bool ID::operator==(const ID& other) const noexcept {
    return std::memcmp(buf_, other.buf_, 16) == 0;
}

bool ID::operator!=(const ID& other) const noexcept {
    return !(*this == other);
}

bool ID::operator<(const ID& other) const noexcept {
    return std::memcmp(buf_, other.buf_, 16) < 0;
}

// Reconstructed from 0x05dacc..0x05e4cc (MDLMessage)
// Tái dựng từ 0x05dacc..0x05e4cc (MDLMessage)
MDLMessage::MDLMessage() : count_(0) {}

MDLMessage::MDLMessage(const MDLMessage& other) : count_(other.count_) {
    for (int32_t i = 0; i < count_ && i < static_cast<int32_t>(kMDLMessageMaxSlots); ++i) {
        slots_[i] = other.slots_[i];
    }
}

MDLMessage& MDLMessage::operator=(const MDLMessage& other) {
    if (this != &other) {
        count_ = other.count_;
        for (int32_t i = 0; i < count_ && i < static_cast<int32_t>(kMDLMessageMaxSlots); ++i) {
            slots_[i] = other.slots_[i];
        }
    }
    return *this;
}

MDLMessage::~MDLMessage() = default;

bool MDLMessage::findIntValue(const char* key, int32_t& out_val) const {
    if (!key || count_ < 1) return false;
    for (int32_t i = 0; i < count_; ++i) {
        if (slots_[i].key == key) {
            out_val = static_cast<int32_t>(slots_[i].int_val);
            return true;
        }
    }
    return false;
}

bool MDLMessage::findLongValue(const char* key, int64_t& out_val) const {
    if (!key || count_ < 1) return false;
    for (int32_t i = 0; i < count_; ++i) {
        if (slots_[i].key == key) {
            out_val = slots_[i].int_val;
            return true;
        }
    }
    return false;
}

bool MDLMessage::findCStringValue(const char* key, char*& out_val) const {
    if (!key || count_ < 1) return false;
    for (int32_t i = 0; i < count_; ++i) {
        if (slots_[i].key == key) {
            out_val = const_cast<char*>(slots_[i].str_val.c_str());
            return true;
        }
    }
    return false;
}

bool MDLMessage::findPairValue(const char* key, MIOPairValue& out_val) const {
    if (!key || count_ < 1) return false;
    for (int32_t i = 0; i < count_; ++i) {
        if (slots_[i].key == key) {
            out_val = slots_[i].pair_val;
            return true;
        }
    }
    return false;
}

bool MDLMessage::findObjectValue(const char* key, MIOObject*& out_val) const {
    if (!key || count_ < 1) return false;
    for (int32_t i = 0; i < count_; ++i) {
        if (slots_[i].key == key) {
            out_val = slots_[i].obj_val;
            return true;
        }
    }
    return false;
}

bool MDLMessage::findUInt64Value(const char* key, uint64_t& out_val) const {
    if (!key || count_ < 1) return false;
    for (int32_t i = 0; i < count_; ++i) {
        if (slots_[i].key == key) {
            out_val = slots_[i].uint_val;
            return true;
        }
    }
    return false;
}

void MDLMessage::setInt32(const char* key, int32_t val) {
    if (!key || count_ > 0x3F) return; // 0x05dfa0: cmp w22, #0x3f; b.gt
    for (int32_t i = 0; i < count_; ++i) {
        if (slots_[i].key == key) {
            slots_[i].value_type = 1;
            slots_[i].int_val = val;
            return;
        }
    }
    if (count_ < static_cast<int32_t>(kMDLMessageMaxSlots)) {
        slots_[count_].value_type = 1;
        slots_[count_].key = key;
        slots_[count_].int_val = val;
        ++count_;
    }
}

void MDLMessage::setInt64(const char* key, int64_t val) {
    if (!key || count_ > 0x3F) return;
    for (int32_t i = 0; i < count_; ++i) {
        if (slots_[i].key == key) {
            slots_[i].value_type = 2;
            slots_[i].int_val = val;
            return;
        }
    }
    if (count_ < static_cast<int32_t>(kMDLMessageMaxSlots)) {
        slots_[count_].value_type = 2;
        slots_[count_].key = key;
        slots_[count_].int_val = val;
        ++count_;
    }
}

void MDLMessage::setString(const char* key, const char* val) {
    if (!key || count_ > 0x3F) return;
    for (int32_t i = 0; i < count_; ++i) {
        if (slots_[i].key == key) {
            slots_[i].value_type = 3;
            slots_[i].str_val = val ? val : "";
            return;
        }
    }
    if (count_ < static_cast<int32_t>(kMDLMessageMaxSlots)) {
        slots_[count_].value_type = 3;
        slots_[count_].key = key;
        slots_[count_].str_val = val ? val : "";
        ++count_;
    }
}

void MDLMessage::setPair(const char* key, MIOPairValue val) {
    if (!key || count_ > 0x3F) return;
    for (int32_t i = 0; i < count_; ++i) {
        if (slots_[i].key == key) {
            slots_[i].value_type = 4;
            slots_[i].pair_val = val;
            return;
        }
    }
    if (count_ < static_cast<int32_t>(kMDLMessageMaxSlots)) {
        slots_[count_].value_type = 4;
        slots_[count_].key = key;
        slots_[count_].pair_val = val;
        ++count_;
    }
}

void MDLMessage::setObject(const char* key, MIOObject* val) {
    if (!key || count_ > 0x3F) return;
    for (int32_t i = 0; i < count_; ++i) {
        if (slots_[i].key == key) {
            slots_[i].value_type = 5;
            slots_[i].obj_val = val;
            return;
        }
    }
    if (count_ < static_cast<int32_t>(kMDLMessageMaxSlots)) {
        slots_[count_].value_type = 5;
        slots_[count_].key = key;
        slots_[count_].obj_val = val;
        ++count_;
    }
}

void MDLMessage::setUInt64(const char* key, uint64_t val) {
    if (!key || count_ > 0x3F) return;
    for (int32_t i = 0; i < count_; ++i) {
        if (slots_[i].key == key) {
            slots_[i].value_type = 6;
            slots_[i].uint_val = val;
            return;
        }
    }
    if (count_ < static_cast<int32_t>(kMDLMessageMaxSlots)) {
        slots_[count_].value_type = 6;
        slots_[count_].key = key;
        slots_[count_].uint_val = val;
        ++count_;
    }
}

bool MDLMessage::isMember(const char* key) const {
    if (!key || count_ < 1) return false;
    for (int32_t i = 0; i < count_; ++i) {
        if (slots_[i].key == key) return true;
    }
    return false;
}

// Reconstructed from 0x05e4cc..0x05ea18 (MDLSingletonsHolder)
// Tái dựng từ 0x05e4cc..0x05ea18 (MDLSingletonsHolder)
MDLSingletonsHolder::MDLSingletonsHolder()
    : strategy_factory_(new MDLStrategyFactory()),
      downloader_factory_(new MDLDownloaderFactory()),
      task_factory_(new MDLTaskFactory()),
      config_center_(new MDLConfigCenter()),
      network_manager_(std::make_shared<MDLNetWorkManager>()),
      file_manager_(nullptr),
      play_info_cache_(new MDLPlayInfoCache()),
      thread_pool_(new MDLThreadPool()),
      buffer_pool_(new MDLRingBufferPool()),
      log_manager_(new MDLLogManager()),
      preload_manager_(new MDLPreloadManager()),
      socket_training_center_(new MDLSocketTrainingCenter()),
      net_speed_engine_(new MDLNetSpeedEngine()),
      event_queue_factory_(new MDLEventQueueFactory()) {}

MDLSingletonsHolder::~MDLSingletonsHolder() {
    delete strategy_factory_;
    delete downloader_factory_;
    delete task_factory_;
    delete config_center_;
    delete file_manager_;
    delete play_info_cache_;
    delete thread_pool_;
    delete buffer_pool_;
    delete log_manager_;
    delete preload_manager_;
    delete socket_training_center_;
    delete net_speed_engine_;
    delete event_queue_factory_;
}

MDLSingletonsHolder* MDLSingletonsHolder::getInstance() {
    static MDLSingletonsHolder* s_instance = new MDLSingletonsHolder();
    return s_instance;
}

void MDLSingletonsHolder::init() {
    if (!file_manager_) {
        file_manager_ = new MDLFileManager();
    }
}

} // namespace ttmio
} // namespace ss
} // namespace com
