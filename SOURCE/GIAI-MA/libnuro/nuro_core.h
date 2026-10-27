// ============================================================================
// Clean-Room C++17 Core Interfaces for libnuro.so (Target 112 / 169)
// Giao diện lõi C++17 sạch cho libnuro.so (Mục tiêu 112 / 169)
// ============================================================================
#pragma once

#include "nuro_types.h"

namespace nuro {

class ILogHandler {
public:
    virtual ~ILogHandler() = default;
    virtual void onLog(LogLevel level, const std::string& message) = 0;
};

class ILogger {
public:
    virtual ~ILogger() = default;
    // 0x02d43c..0x02d4ac
    static void registerHandler(const std::shared_ptr<ILogHandler>& handler);
    // 0x02d658..0x02d6c8
    static void setLogLevel(LogLevel level);
    static LogLevel getLogLevel();
    static void log(LogLevel level, const char* file, int line, const char* func, const char* fmt_msg);
};

class MessageUtils {
public:
    // 0x02e38c..0x02e99c (1,552 bytes)
    static std::string toolCalls2JsonString(const std::vector<ToolCall>& tool_calls);
};

class ConversationListener {
public:
    virtual ~ConversationListener() = default;
    virtual void onAck(const std::string& local_msg_id, AckStatus status) = 0;
    virtual void onAssistantMessage(const AssistantMessage& msg) = 0;
    virtual void onUserMessage(const UserMessage& msg) = 0;
    virtual void onSystemMessage(int32_t code, const std::string& text) = 0;
    virtual void onSectionStatus(SectionStatus status, MessageSource source, const SectionInfo& info) = 0;
    virtual void onRecoverStatus(RecoverStatus status, const std::string& next_cursor, bool has_more) = 0;
    virtual void onTracingEvent(const std::string& event_json) = 0;
};

class Conversation {
public:
    virtual ~Conversation() = default;
    virtual void listen(const std::shared_ptr<ConversationListener>& listener) = 0;
    virtual bool connect() = 0;
    virtual bool send(const InputMessage& msg) = 0;
    virtual bool reply(const InputMessage& msg) = 0;
    virtual bool retry(const std::string& local_msg_id) = 0;
    virtual bool cancel() = 0;
    virtual int32_t popupHistoryMessages(bool only_latest_section) = 0;
    virtual void setRunMode(RunMode mode) = 0;
    virtual void setBabiParams(const std::string& babi_json) = 0;
    virtual bool recoverRemoteSection() = 0;
    virtual void cancelRecoverRemoteSection() = 0;
    virtual bool recoverRemoteSections(const std::string& cursor, int32_t count) = 0;
    virtual void cancelRecoverRemoteSections() = 0;
    virtual std::string takeXray() = 0;
};

class ConversationHub {
public:
    virtual ~ConversationHub() = default;
    // 0x017a64..0x017b48 (228 bytes)
    static std::shared_ptr<ConversationHub> instance();
    virtual void config(const Config& cfg) = 0;
    virtual std::shared_ptr<Conversation> open(const std::string& local_conversation_id, const ConversationOptions& opts) = 0;
    virtual void close(const std::string& local_conversation_id) = 0;
    virtual std::vector<ConversationInfo> list() = 0;
    virtual bool remove(const std::string& local_conversation_id) = 0;
};

class SyncChannel {
public:
    virtual ~SyncChannel() = default;
    // 0x07c7b4..0x07c87c
    static std::shared_ptr<SyncChannel> create(const SyncChannelOptions& options);
    virtual void sync(const std::string& key, const std::string& payload) = 0;
    virtual void flush() = 0;
};

uint64_t execute_fde_shard_1(uint32_t fde_idx, uint64_t a0, uint64_t a1);
uint64_t execute_fde_shard_2(uint32_t fde_idx, uint64_t a0, uint64_t a1);
uint64_t execute_fde_shard_3(uint32_t fde_idx, uint64_t a0, uint64_t a1);
uint64_t execute_fde_shard_4(uint32_t fde_idx, uint64_t a0, uint64_t a1);
uint64_t execute_fde_shard_5(uint32_t fde_idx, uint64_t a0, uint64_t a1);

} // namespace nuro
