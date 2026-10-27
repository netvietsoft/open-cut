// ============================================================================
// Clean-Room C++17 ABI & Data Structures for libnuro.so (Target 112 / 169)
// Cấu trúc dữ liệu & ABI C++17 sạch cho libnuro.so (Mục tiêu 112 / 169)
// Binary Size: 953,040 bytes | SHA-256: 3f62590d84f43083524aa061a54045dc541947328447a446ee253d59b2a160c3
// .eh_frame_hdr: 1,835 FDEs @ 0x0b8c58 | .dynsym: 176 Exported Symbols @ 0x001128
// ============================================================================
#pragma once

#include <cstdint>
#include <cstddef>
#include <string>
#include <vector>
#include <optional>
#include <memory>
#include <unordered_map>
#include <mutex>
#include <atomic>

namespace nuro {

// Enums observed in com/lemon/nuro/* Djinni descriptors (.rodata 0x0b5b67..0x0b86f5)
// Các kiểu liệt kê quan sát từ mô tả Djinni com/lemon/nuro/* (.rodata 0x0b5b67..0x0b86f5)
enum class LogLevel : int32_t {
    VERBOSE = 0,
    DEBUG_LEVEL = 1,
    INFO = 2,
    WARN = 3,
    ERROR_LEVEL = 4
};

enum class RunMode : int32_t {
    NORMAL = 0,
    DEBUG_MODE = 1,
    DRY_RUN = 2
};

enum class MessageStatus : int32_t {
    SENDING = 0,
    SENT = 1,
    STREAMING = 2,
    COMPLETED = 3,
    FAILED = 4,
    CANCELLED = 5
};

enum class MessageSource : int32_t {
    LOCAL = 0,
    REMOTE = 1,
    HISTORY = 2
};

enum class AckStatus : int32_t {
    OK = 0,
    TIMEOUT = 1,
    FAILED = 2
};

enum class SectionStatus : int32_t {
    ON_GOING = 0,
    COMPLETED = 1,
    FAILED = 2,
    CANCELLED = 3
};

enum class RecoverStatus : int32_t {
    START = 0,
    FINISH = 1,
    FAILED = 2,
    CANCELLED = 3
};

enum class FileSourceType : int32_t {
    LOCAL_PATH = 0,
    REMOTE_URI = 1,
    CLOUD_URL = 2
};

enum class ToolCallComposeType : int32_t {
    NONE = 0,
    PARALLEL = 1,
    SEQUENTIAL = 2
};

enum class ToolResultStatus : int32_t {
    SUCCESS = 0,
    ERROR_STATUS = 1,
    CANCELLED = 2
};

enum class SyncInfoType : int32_t {
    TEXT = 0,
    FILE = 1,
    PATCH = 2
};

enum class HttpRequestScene : int32_t {
    RECOVER_SECTION = 0,
    RECOVER_SECTIONS = 1,
    SYNC_CHANNEL = 2
};

enum class HttpMethod : int32_t {
    GET = 0,
    POST = 1
};

// Exact 112-byte (0x70) layout verified at nuro::FileInfo::FileInfo(const FileInfo&) (0x022610..0x0226fc)
// Bố cục chuẩn 112-byte (0x70) xác minh tại nuro::FileInfo::FileInfo(const FileInfo&) (0x022610..0x0226fc)
struct FileInfo {
    int32_t file_type{0};             // +0x00 (ldr w8, [x1], #8; str w8, [x0])
    int32_t reserved_04{0};           // +0x04
    std::string file_id;              // +0x08 (24 bytes SSO string)
    FileSourceType source_type{FileSourceType::LOCAL_PATH}; // +0x20 (ldr w8, [x22, #0x20])
    int32_t reserved_24{0};           // +0x24
    std::string uri;                  // +0x28 (24 bytes SSO string)
    std::string url;                  // +0x40 (24 bytes SSO string)
    std::string meta;                 // +0x58 (24 bytes SSO string)

    FileInfo() = default;
    FileInfo(const FileInfo& other);
};

// Exact 120-byte (0x78) layout verified at nuro::ToolCallResult::ToolCallResult(const ToolCallResult&) (0x022ab8..0x022bd0)
// Bố cục chuẩn 120-byte (0x78) xác minh tại nuro::ToolCallResult::ToolCallResult(const ToolCallResult&) (0x022ab8..0x022bd0)
struct ToolCallResult {
    std::string call_id;              // +0x00
    std::string name;                 // +0x18
    std::string result;               // +0x30
    ToolResultStatus status{ToolResultStatus::SUCCESS}; // +0x48 (ldr w8, [x21, #0x48])
    int32_t reserved_4c{0};           // +0x4c
    std::optional<std::string> err_msg; // +0x50 string, +0x68 has_value (ldrb w8, [x21, #0x68])
    int32_t err_code{0};              // +0x70 (ldr w8, [x21, #0x70])
    int32_t reserved_74{0};           // +0x74

    ToolCallResult() = default;
    ToolCallResult(const ToolCallResult& other);
};

// Exact 96-byte (0x60) layout verified at nuro::ToolResult::ToolResult(const ToolResult&) (0x0228c0..0x0229d4)
// Bố cục chuẩn 96-byte (0x60) xác minh tại nuro::ToolResult::ToolResult(const ToolResult&) (0x0228c0..0x0229d4)
struct ToolResult {
    std::vector<std::string> patch_list;        // +0x00 (24 bytes vector)
    std::vector<ToolCallResult> tool_call_results; // +0x18 (24 bytes vector)
    ToolResultStatus status{ToolResultStatus::SUCCESS}; // +0x30 (ldr w8, [x20, #0x30])
    int32_t reserved_34{0};                     // +0x34
    std::optional<std::string> err_msg;         // +0x38 string, +0x50 has_value (ldrb w8, [x20, #0x50])
    int32_t err_code{0};                        // +0x58 (ldr w8, [x20, #0x58])
    int32_t reserved_5c{0};                     // +0x5c

    ToolResult() = default;
    ToolResult(const ToolResult& other);
};

// Exact 144-byte (0x90) layout verified at nuro::ToolCall::ToolCall(const ToolCall&) (0x0659f0..0x065bd8)
// Bố cục chuẩn 144-byte (0x90) xác minh tại nuro::ToolCall::ToolCall(const ToolCall&) (0x0659f0..0x065bd8)
struct ToolCall {
    std::string id;                   // +0x00
    std::string type;                 // +0x18
    std::string name;                 // +0x30
    ToolCallComposeType compose_type{ToolCallComposeType::NONE}; // +0x48 (ldr w8, [x22, #0x48])
    int32_t reserved_4c{0};           // +0x4c
    std::optional<std::vector<std::string>> patch_list; // +0x50 vector, +0x68 has_value (ldrb w8, [x22, #0x68])
    std::optional<std::string> arguments; // +0x70 string, +0x88 has_value (ldrb w8, [x22, #0x88])

    ToolCall() = default;
    ToolCall(const ToolCall& other);
    ~ToolCall();
};

// Exact 80-byte (0x50) layout verified at nuro::ConversationInfo::operator=(ConversationInfo&&) (0x073ee0..0x073ffc)
// Bố cục chuẩn 80-byte (0x50) xác minh tại nuro::ConversationInfo::operator=(ConversationInfo&&) (0x073ee0..0x073ffc)
struct ConversationInfo {
    std::string local_conversation_id; // +0x00 (24 bytes)
    std::string conversation_id;       // +0x18 (24 bytes)
    std::string name;                  // +0x30 (24 bytes)
    int64_t create_time{0};            // +0x48 (ldr x8, [x20, #0x48]; str x8, [x19, #0x48])

    ConversationInfo() = default;
    ConversationInfo(ConversationInfo&& other) noexcept;
    ConversationInfo& operator=(ConversationInfo&& other) noexcept;
    ConversationInfo(const ConversationInfo&) = default;
    ConversationInfo& operator=(const ConversationInfo&) = default;
};

struct SectionInfo {
    std::string section_id;
    std::string local_section_id;
};

struct MessageContent {
    std::string text;
    std::vector<FileInfo> files;
};

struct Context {
    std::string draft_meta;
    std::vector<FileInfo> attachments;
    std::string extra_json;

    Context() = default;
    Context(const Context& other);
    ~Context();
};

struct InputMessage {
    std::string local_message_id;
    std::optional<MessageContent> content;
    std::optional<Context> context;
    std::optional<ToolResult> tool_result;
    std::optional<std::string> action;

    InputMessage() = default;
    InputMessage(std::string local_msg_id,
                 std::optional<MessageContent> content_opt,
                 std::optional<Context> context_opt,
                 std::optional<ToolResult> tool_result_opt,
                 std::optional<std::string> action_opt);
    ~InputMessage();
};

struct UserMessage {
    std::string local_message_id;
    std::string message_id;
    std::optional<SectionInfo> section_info;
    std::optional<MessageContent> content;
    std::optional<Context> context;
    std::optional<ToolResult> tool_result;
    MessageStatus status{MessageStatus::SENT};
    std::optional<std::string> action;
    std::optional<std::string> extra;
    int64_t create_time{0};
    MessageSource source{MessageSource::LOCAL};

    UserMessage() = default;
    UserMessage(const UserMessage& other);
    ~UserMessage();
};

struct AssistantMessage {
    std::string message_id;
    MessageStatus status{MessageStatus::COMPLETED};
    std::optional<MessageContent> content;
    std::vector<ToolCall> tool_calls;
    std::optional<SectionInfo> section_info;
    MessageSource source{MessageSource::REMOTE};

    AssistantMessage() = default;
    ~AssistantMessage();
};

struct Config {
    std::string cache_path;
};

struct ConversationOptions {
    std::string name;
    int32_t history_message_limit{100};
    int32_t uplink_message_ack_timeout_ms{5000};
    int32_t max_resend_uplink_message_count{3};
    bool block_on_recover{false};
};

struct SyncChannelOptions {
    int32_t send_interval_ms{1000};
    int32_t max_stash_count{50};
    std::string compression_algo{"gzip"};
};

} // namespace nuro
