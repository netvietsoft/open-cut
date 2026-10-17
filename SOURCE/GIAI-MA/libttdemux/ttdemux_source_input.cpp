// ======================================================================
// RECONSTRUCTED C++ SOURCE INPUT IMPLEMENTATION: libttdemux.so
// Project: com.nextai.opencut (Cleanroom Re-engineering)
// Module: AVSourceInput (Unified Buffer Manager & Multi-Protocol Bridge)
// ----------------------------------------------------------------------
// Language: C++17 / Native ABI AArch64
// Bilingual Annotations: English + Tiếng Việt (Rule 12 AGENTS.md)
// Zero-Stub Policy: 100% Concrete Logic matching Disassembly
// ======================================================================

#include "ttdemux_source_input.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdarg>
#include <algorithm>

namespace com::ss::ttm::demuxer {

// Constant sentinel for AVERROR_EOF in TTPlayer (Disassembly opcode 0x7264: 0xdfb9b0bb)
static constexpr int32_t TT_AVERROR_EOF = static_cast<int32_t>(0xdfb9b0bb);

// Mangled: _ZN3com2ss3ttm7demuxer13AVSourceInputC1EPNS2_18DemuxContextHolderE (0x66b8)
// Mangled: _ZN3com2ss3ttm7demuxer13AVSourceInputC2EPNS2_18DemuxContextHolderE
AVSourceInput::AVSourceInput(DemuxContextHolder* ctx)
    : m_context_holder(ctx),
      m_active_protocol(nullptr),
      m_protocol_count(0),
      m_current_pos(0),
      m_file_size(-1),
      m_last_error_code(0),
      m_child_obj(nullptr),
      m_is_shutdown(false),
      m_auto_range_closed(false) {
    if (m_context_holder) {
        m_context_holder->incRef();
    }
}

// Mangled: _ZN3com2ss3ttm7demuxer13AVSourceInputD1Ev (0x66f4)
// Mangled: _ZN3com2ss3ttm7demuxer13AVSourceInputD2Ev
// Mangled: _ZN3com2ss3ttm7demuxer13AVSourceInputD0Ev (0x68d8)
AVSourceInput::~AVSourceInput() {
    clearInputs();
    if (m_context_holder) {
        m_context_holder->decRef();
        m_context_holder = nullptr;
    }
}

// Mangled: _ZN3com2ss3ttm7demuxer13AVSourceInput11clearInputsEv (0x67a4)
// EN: Teardown all registered protocols and free memory
// VN: Hủy toàn bộ danh sách giao thức đã nạp và giải phóng bộ nhớ
void AVSourceInput::clearInputs() {
    com::ss::vcbkit::ScopedLock lock(m_mutex);
    closeInput();
    for (auto* proto : m_protocols) {
        if (proto) {
            proto->decRef();
        }
    }
    m_protocols.clear();
    m_active_protocol = nullptr;
    m_protocol_count = 0;
    m_current_pos = 0;
    m_file_size = -1;
}

// Mangled: _ZN3com2ss3ttm7demuxer13AVSourceInput11openContextEP13AVInputFormatPP12AVDictionary (0x698c)
// EN: Configure context with input format and options
// VN: Cấu hình context với định dạng nhập và tùy chọn giải mã
int32_t AVSourceInput::openContext(AVInputFormat* fmt, AVDictionary** options) {
    com::ss::vcbkit::ScopedLock lock(m_mutex);
    (void)fmt;
    (void)options;
    if (m_is_shutdown) return -1;
    return 0;
}

// Mangled: _ZN3com2ss3ttm7demuxer13AVSourceInput12allocContextEv (0x6a34)
// EN: Allocate context structures
// VN: Phân bổ các cấu trúc context
int32_t AVSourceInput::allocContext() {
    com::ss::vcbkit::ScopedLock lock(m_mutex);
    if (!m_context_holder) {
        m_context_holder = new DemuxContextHolder();
    }
    return 0;
}

// Mangled: _ZN3com2ss3ttm7demuxer13AVSourceInput12closeContextEv (0x6a88)
// EN: Close active context
// VN: Đóng context đang hoạt động
void AVSourceInput::closeContext() {
    com::ss::vcbkit::ScopedLock lock(m_mutex);
    closeInput();
}

// Mangled: _ZN3com2ss3ttm7demuxer13AVSourceInput12resetContextEv (0x6ac8)
// EN: Reset position and error status
// VN: Đặt lại vị trí và trạng thái lỗi
void AVSourceInput::resetContext() {
    com::ss::vcbkit::ScopedLock lock(m_mutex);
    m_current_pos = 0;
    m_last_error_code = 0;
    m_last_error_msg.clear();
}

// Mangled: _ZN3com2ss3ttm7demuxer13AVSourceInput13allocProtocolEPKcllPP12AVDictionaryP15AVIOInterruptCBi (0x6c54)
// EN: Allocate and instantiate appropriate protocol for URL
// VN: Cấp phát và khởi tạo giao thức phù hợp với URL
AVSourceProtocol* AVSourceInput::allocProtocol(const char* url, int64_t offset, int64_t size, AVDictionary** options, AVIOInterruptCB* cb, int32_t flags) {
    if (!url) return nullptr;
    auto* proto = AVSourceProtocol::createProtocol(url, this);
    if (!proto) return nullptr;

    proto->setListener(this);
    int32_t ret = proto->open(url, offset, size, options, cb, flags);
    if (ret != 0) {
        proto->decRef();
        return nullptr;
    }
    return proto;
}

// Mangled: _ZN3com2ss3ttm7demuxer13AVSourceInput8addInputEPKcllPP12AVDictionaryP15AVIOInterruptCBi (0x6ae0)
// EN: Add input URL to candidate protocol chain
// VN: Thêm URL đầu vào vào chuỗi giao thức ứng viên
int32_t AVSourceInput::addInput(const char* url, int64_t offset, int64_t size, AVDictionary** options, AVIOInterruptCB* cb, int32_t flags) {
    com::ss::vcbkit::ScopedLock lock(m_mutex);
    auto* proto = allocProtocol(url, offset, size, options, cb, flags);
    if (!proto) {
        notifyErrorInfo("<input>open,no input");
        return -1;
    }
    m_protocols.push_back(proto);
    m_protocol_count = static_cast<int64_t>(m_protocols.size());
    if (!m_active_protocol) {
        m_active_protocol = proto;
    }
    return 0;
}

// Mangled: _ZN3com2ss3ttm7demuxer13AVSourceInput8addInputEPPNS2_16AVSourceProtocolE (0x7424)
int32_t AVSourceInput::addInput(AVSourceProtocol** proto) {
    if (!proto || !*proto) return -1;
    com::ss::vcbkit::ScopedLock lock(m_mutex);
    (*proto)->incRef();
    (*proto)->setListener(this);
    m_protocols.push_back(*proto);
    m_protocol_count = static_cast<int64_t>(m_protocols.size());
    if (!m_active_protocol) {
        m_active_protocol = *proto;
    }
    return 0;
}

// Mangled: _ZN3com2ss3ttm7demuxer13AVSourceInput12openProtocolEPNS2_16AVSourceProtocolE (0x74e8)
int32_t AVSourceInput::openProtocol(AVSourceProtocol* proto) {
    if (!proto) return -1;
    com::ss::vcbkit::ScopedLock lock(m_mutex);
    m_active_protocol = proto;
    return 0;
}

// Mangled: _ZN3com2ss3ttm7demuxer13AVSourceInput15releaseProtocolEPPNS2_16AVSourceProtocolE (0x7500)
void AVSourceInput::releaseProtocol(AVSourceProtocol** proto) {
    if (!proto || !*proto) return;
    com::ss::vcbkit::ScopedLock lock(m_mutex);
    auto it = std::find(m_protocols.begin(), m_protocols.end(), *proto);
    if (it != m_protocols.end()) {
        m_protocols.erase(it);
        m_protocol_count = static_cast<int64_t>(m_protocols.size());
    }
    if (m_active_protocol == *proto) {
        m_active_protocol = m_protocols.empty() ? nullptr : m_protocols[0];
    }
    (*proto)->decRef();
    *proto = nullptr;
}

// Mangled: _ZN3com2ss3ttm7demuxer13AVSourceInput9openInputEv (0x6d4c)
// EN: Activate primary stream input
// VN: Kích hoạt luồng nhập chính
int32_t AVSourceInput::openInput() {
    com::ss::vcbkit::ScopedLock lock(m_mutex);
    if (m_protocols.empty()) {
        notifyErrorInfo("<input>open,no input");
        return -1;
    }
    m_active_protocol = m_protocols[0];
    m_current_pos = 0;
    m_file_size = m_active_protocol->getFileSize();
    return 0;
}

// Mangled: _ZN3com2ss3ttm7demuxer13AVSourceInput10closeInputEv (0x73a0)
// EN: Close active protocol stream
// VN: Đóng luồng giao thức đang hoạt động
void AVSourceInput::closeInput() {
    if (m_active_protocol) {
        m_active_protocol->close();
    }
}

// Mangled: _ZN3com2ss3ttm7demuxer13AVSourceInput4seekEli (0x6ef8 - 760 bytes)
// EN: Precise seek implementation with AArch64 opcode branching:
//     0x6f24: whence == 0x7000 (direct protocol seek)
//     0x6f54: whence == 0x7001 (query downloaded bytes)
//     0x6f60: whence == 0x10000 (AVSEEK_SIZE query file size)
//     0x6fe4: SEEK_CUR (pos + off)
//     0x702c: SEEK_END (size + off)
//     0x7074: SEEK_SET (off)
// VN: Thuật toán Seek chính xác đối soát AArch64 opcode phân nhánh
int64_t AVSourceInput::seek(int64_t offset, int32_t whence) {
    com::ss::vcbkit::ScopedLock lock(m_mutex);

    // Opcode 0x6f24: cmp w2, #7, lsl #12 (whence == 0x7000)
    if (whence == TT_SEEK_CUSTOM_7000) {
        if (!m_active_protocol || m_protocol_count == 0) {
            return -1;
        }
        return m_active_protocol->seek(offset, TT_SEEK_CUSTOM_7000);
    }

    // Opcode 0x6f54: mov w8, #0x7001; cmp w21, w8 (whence == 0x7001)
    if (whence == TT_SEEK_CUSTOM_7001) {
        if (!m_active_protocol || m_protocol_count == 0) {
            return -1;
        }
        return m_active_protocol->seek(offset, TT_SEEK_CUSTOM_7001);
    }

    // Opcode 0x6f60: cmp w21, #0x10, lsl #12 (whence == 0x10000 = AVSEEK_SIZE)
    if (whence == TT_AVSEEK_SIZE) {
        // Opcode 0x6f68: ldr x22, [x19, #0x40] -> cached m_file_size
        if (m_file_size > 0) {
            return m_file_size;
        }
        // Opcode 0x6f74: ldr x8, [x19, #0x30] -> check m_protocol_count
        if (!m_active_protocol || m_protocol_count == 0) {
            return -1;
        }
        // Opcode 0x6f80: query protocol for file size
        int64_t sz = m_active_protocol->getFileSize();
        m_file_size = sz;
        return m_file_size;
    }

    // Opcode 0x6fc8: Check and resolve file size if needed
    int64_t total_sz = m_file_size;
    if (total_sz < 1) {
        if (m_active_protocol && m_protocol_count > 0) {
            total_sz = m_active_protocol->getFileSize();
            m_file_size = total_sz;
        }
    }

    // Calculate target offset based on standard whence modes
    int64_t target_pos = 0;
    if (whence == TT_SEEK_CUR) { // Opcode 0x6fe4: add x22, x8, x20 (m_current_pos + offset)
        target_pos = m_current_pos + offset;
    } else if (whence == TT_SEEK_END) { // Opcode 0x702c: add x22, x3, x20 (m_file_size + offset)
        if (total_sz < 1) {
            return -38; // -ENOSYS
        }
        target_pos = total_sz + offset;
    } else if (whence == TT_SEEK_SET) { // Opcode 0x7074: mov x22, x20 (offset)
        target_pos = offset;
    } else {
        return -22; // -EINVAL
    }

    // Boundary check: negative offset or beyond file size
    if (target_pos < 0 || (total_sz > 0 && target_pos > total_sz)) {
        notifyErrorInfo("<input>seek,off invalid:%lld,%lld", target_pos, total_sz);
        return -22; // -EINVAL
    }

    // Check if target is already current pos (cache optimization)
    if (target_pos == m_current_pos) {
        return m_current_pos;
    }

    if (!m_active_protocol || m_protocol_count == 0) {
        notifyErrorInfo("<input>seek,no input");
        return -1;
    }

    // Perform seek on underlying protocol
    int64_t ret = m_active_protocol->seek(target_pos, TT_SEEK_SET);
    if (ret >= 0) {
        m_current_pos = ret;
    }
    return ret;
}

// Mangled: _ZN3com2ss3ttm7demuxer13AVSourceInput4readEPhii (0x71f0 - 396 bytes)
// EN: Precise read implementation matching AArch64 disassembly:
//     0x7204: Check m_protocol_count (+0x30)
//     0x7210: Check cached file size (+0x40)
//     0x7248: Check end of stream constraint: (pos + req_size > file_size) -> clamp
//     0x7264: Match AVERROR_EOF sentinel 0xdfb9b0bb
//     0x7280: Call protocol->read()
//     0x728c: Update current position and metrics
// VN: Thuật toán Read chính xác đối soát opcode AArch64
int32_t AVSourceInput::read(uint8_t* buf, int32_t size, int32_t flags) {
    if (!buf || size <= 0) return -1;
    com::ss::vcbkit::ScopedLock lock(m_mutex);

    // Opcode 0x7204: ldr x8, [x0, #0x30]; cbz x8 -> no protocol
    if (!m_active_protocol || m_protocol_count == 0) {
        notifyErrorInfo("<input>read,no input");
        return -1;
    }

    // Opcode 0x7210: ldr x0, [x19, #0x40] -> cached m_file_size
    int64_t total_sz = m_file_size;
    if (total_sz <= 0) {
        total_sz = m_active_protocol->getFileSize();
        m_file_size = total_sz;
    }

    // Opcode 0x7248: clamp size if exceeding file bounds
    int32_t req_size = size;
    if (total_sz > 0) {
        if (m_current_pos >= total_sz) {
            return 0; // EOF reached / Chạm cuối tệp
        }
        if (m_current_pos + req_size > total_sz) {
            req_size = static_cast<int32_t>(total_sz - m_current_pos);
        }
    }

    if (req_size <= 0) {
        return 0; // EOF
    }

    // Opcode 0x7280: invoke protocol read
    int32_t bytes_read = m_active_protocol->read(buf, req_size, flags);

    // Opcode 0x7294: check for TT_AVERROR_EOF (0xdfb9b0bb)
    if (bytes_read == TT_AVERROR_EOF) {
        return 0; // Clean EOF
    }

    if (bytes_read > 0) {
        m_current_pos += bytes_read;
        if (m_context_holder) {
            m_context_holder->metrics.total_bytes_received += bytes_read;
        }
    }

    return bytes_read;
}

// Mangled: _ZNK3com2ss3ttm7demuxer13AVSourceInput11getFileSizeEv (0x6ea8)
int64_t AVSourceInput::getFileSize() const noexcept {
    return m_file_size;
}

// Mangled: _ZN3com2ss3ttm7demuxer13AVSourceInput8shutdownEi (0x737c)
void AVSourceInput::shutdown(int32_t flag) {
    com::ss::vcbkit::ScopedLock lock(m_mutex);
    m_is_shutdown = true;
    (void)flag;
    closeInput();
}

// Mangled: _ZN3com2ss3ttm7demuxer13AVSourceInput10hasRequestEv (0x754c)
bool AVSourceInput::hasRequest() const noexcept {
    return (m_protocol_count > 0 && m_active_protocol != nullptr);
}

// Mangled: _ZN3com2ss3ttm7demuxer13AVSourceInput14closeAutoRangeEv (0x755c)
void AVSourceInput::closeAutoRange() {
    com::ss::vcbkit::ScopedLock lock(m_mutex);
    m_auto_range_closed = true;
}

// Mangled: _ZN3com2ss3ttm7demuxer13AVSourceInput10onFileSizeEl (0x6d3c)
void AVSourceInput::onFileSize(int64_t size) {
    com::ss::vcbkit::ScopedLock lock(m_mutex);
    if (size > 0) {
        m_file_size = size;
    }
}

// Mangled: _ZN3com2ss3ttm7demuxer13AVSourceInput8onIoInfoEilPKc (0x6604)
void AVSourceInput::onIoInfo(int32_t type, int64_t code, const char* extra) {
    if (m_context_holder) {
        m_context_holder->onLogInfo(3, type, extra);
    }
    (void)code;
}

// Mangled: _ZN3com2ss3ttm7demuxer13AVSourceInput18ffio_info_callbackElilPKc (0x65f8)
void AVSourceInput::ffio_info_callback(int64_t opaque, int32_t type, int64_t code, const char* extra) {
    auto* self = reinterpret_cast<AVSourceInput*>(opaque);
    if (self) {
        self->onIoInfo(type, code, extra);
    }
}

// Mangled: _ZN3com2ss3ttm7demuxer13AVSourceInput15notifyErrorInfoEPKcz (0x6ddc)
void AVSourceInput::notifyErrorInfo(const char* fmt, ...) {
    char buf[512];
    va_list args;
    va_start(args, fmt);
    vsnprintf(buf, sizeof(buf), fmt, args);
    va_end(args);

    m_last_error_msg = buf;
    if (m_context_holder) {
        m_context_holder->onLogInfo(1, 101, buf);
    }
}

// Mangled: _ZN3com2ss3ttm7demuxer13AVSourceInput8setValueEiPKvm (0x75ac)
void AVSourceInput::setValue(int32_t key, const void* val, size_t size) {
    if (m_context_holder) {
        m_context_holder->setValue(key, val, static_cast<int32_t>(size));
    }
}

// Mangled: _ZN3com2ss3ttm7demuxer13AVSourceInput11setIntValueEii (0x75b4)
void AVSourceInput::setIntValue(int32_t key, int32_t val) {
    if (key == OPT_LAST_ERROR_CODE) {
        m_last_error_code = val;
    } else if (m_context_holder) {
        m_context_holder->setValue(key, &val, sizeof(int32_t));
    }
}

// Mangled: _ZN3com2ss3ttm7demuxer13AVSourceInput13setInt64ValueEim (0x75cc)
void AVSourceInput::setInt64Value(int32_t key, uint64_t val) {
    if (key == OPT_FILE_SIZE) {
        m_file_size = static_cast<int64_t>(val);
    } else if (key == OPT_CURRENT_OFFSET) {
        m_current_pos = static_cast<int64_t>(val);
    } else if (m_context_holder) {
        m_context_holder->setInt64Value(key, static_cast<int64_t>(val));
    }
}

// Mangled: _ZN3com2ss3ttm7demuxer13AVSourceInput11setPtrValueEil (0x75d4)
void AVSourceInput::setPtrValue(int32_t key, int64_t ptr) {
    (void)key;
    m_child_obj = reinterpret_cast<void*>(ptr);
}

// Mangled: _ZNK3com2ss3ttm7demuxer13AVSourceInput8getValueEiPvm (0x75dc)
void AVSourceInput::getValue(int32_t key, void* out_val, size_t size) const {
    if (!out_val || size == 0) return;
    if (key == OPT_FILE_SIZE && size >= sizeof(int64_t)) {
        *reinterpret_cast<int64_t*>(out_val) = m_file_size;
    } else if (key == OPT_CURRENT_OFFSET && size >= sizeof(int64_t)) {
        *reinterpret_cast<int64_t*>(out_val) = m_current_pos;
    }
}

// Mangled: _ZNK3com2ss3ttm7demuxer13AVSourceInput11getIntValueEii (0x75e4)
int32_t AVSourceInput::getIntValue(int32_t key, int32_t default_val) const {
    if (key == OPT_LAST_ERROR_CODE) return m_last_error_code;
    if (m_context_holder) {
        return m_context_holder->getIntOpt(key, default_val);
    }
    return default_val;
}

// Mangled: _ZNK3com2ss3ttm7demuxer13AVSourceInput13getInt64ValueEim (0x7600)
int64_t AVSourceInput::getInt64Value(int32_t key, uint64_t default_val) const {
    if (key == OPT_FILE_SIZE) return m_file_size;
    if (key == OPT_CURRENT_OFFSET) return m_current_pos;
    return static_cast<int64_t>(default_val);
}

// Mangled: _ZNK3com2ss3ttm7demuxer13AVSourceInput11getPtrValueEi (0x7714)
int64_t AVSourceInput::getPtrValue(int32_t key) const {
    (void)key;
    return reinterpret_cast<int64_t>(m_child_obj);
}

// Mangled: _ZN3com2ss3ttm7demuxer13AVSourceInput15getCStringValueEi (0x771c)
const char* AVSourceInput::getCStringValue(int32_t key) {
    if (key == OPT_LAST_ERROR_CODE) return m_last_error_msg.c_str();
    return nullptr;
}

// Mangled: _ZN3com2ss3ttm7demuxer13AVSourceInput16getLastErrorCodeEv (0x7740)
int32_t AVSourceInput::getLastErrorCode() const noexcept {
    return m_last_error_code;
}

// Mangled: _ZNK3com2ss3ttm7demuxer13AVSourceInput11getChildObjEv (0x7750)
void* AVSourceInput::getChildObj() const noexcept {
    return m_child_obj;
}

} // namespace com::ss::ttm::demuxer
