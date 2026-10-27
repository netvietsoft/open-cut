// ============================================================================
// Clean-Room C++17 Core Implementation for libnuro.so (Target 112 / 169)
// Hiện thực C++17 sạch lõi cho libnuro.so (conversation_hub.cpp, conversation_impl.cpp, history_manager.cpp)
// ============================================================================
#include "nuro_core.h"
#include <sstream>
#include <algorithm>
#include <chrono>

namespace nuro {

namespace {
std::mutex g_logger_mutex;
std::shared_ptr<ILogHandler> g_log_handler;
std::atomic<int32_t> g_log_level{static_cast<int32_t>(LogLevel::INFO)};
} // namespace

// Reconstructed from 0x02d43c..0x02d4ac (.bss singleton @ 0x0ec320, guard @ 0x0ec338)
// Tái dựng từ 0x02d43c..0x02d4ac (singleton tại .bss 0x0ec320, biến canh tại 0x0ec338)
void ILogger::registerHandler(const std::shared_ptr<ILogHandler>& handler) {
    std::lock_guard<std::mutex> lock(g_logger_mutex);
    g_log_handler = handler;
}

// Reconstructed from 0x02d658..0x02d6c8
// Tái dựng từ 0x02d658..0x02d6c8
void ILogger::setLogLevel(LogLevel level) {
    g_log_level.store(static_cast<int32_t>(level), std::memory_order_release);
}

LogLevel ILogger::getLogLevel() {
    return static_cast<LogLevel>(g_log_level.load(std::memory_order_acquire));
}

void ILogger::log(LogLevel level, const char* file, int line, const char* func, const char* fmt_msg) {
    if (static_cast<int32_t>(level) < g_log_level.load(std::memory_order_acquire)) {
        return;
    }
    std::shared_ptr<ILogHandler> h;
    {
        std::lock_guard<std::mutex> lock(g_logger_mutex);
        h = g_log_handler;
    }
    if (h) {
        std::ostringstream oss;
        oss << "[" << (file ? file : "nuro") << ":" << line << " " << (func ? func : "") << "] " << (fmt_msg ? fmt_msg : "");
        h->onLog(level, oss.str());
    }
}

// Reconstructed from 0x022610..0x0226fc (236 bytes, 0x70 struct layout)
// Tái dựng từ 0x022610..0x0226fc (236 bytes, bố cục struct 0x70)
FileInfo::FileInfo(const FileInfo& other)
    : file_type(other.file_type),
      reserved_04(other.reserved_04),
      file_id(other.file_id),
      source_type(other.source_type),
      reserved_24(other.reserved_24),
      uri(other.uri),
      url(other.url),
      meta(other.meta) {}

// Reconstructed from 0x022ab8..0x022bd0 (280 bytes, 0x78 struct layout)
// Tái dựng từ 0x022ab8..0x022bd0 (280 bytes, bố cục struct 0x78)
ToolCallResult::ToolCallResult(const ToolCallResult& other)
    : call_id(other.call_id),
      name(other.name),
      result(other.result),
      status(other.status),
      reserved_4c(other.reserved_4c),
      err_msg(other.err_msg),
      err_code(other.err_code),
      reserved_74(other.reserved_74) {}

// Reconstructed from 0x0228c0..0x0229d4 (276 bytes, 0x60 struct layout)
// Tái dựng từ 0x0228c0..0x0229d4 (276 bytes, bố cục struct 0x60)
ToolResult::ToolResult(const ToolResult& other)
    : patch_list(other.patch_list),
      tool_call_results(other.tool_call_results),
      status(other.status),
      reserved_34(other.reserved_34),
      err_msg(other.err_msg),
      err_code(other.err_code),
      reserved_5c(other.reserved_5c) {}

// Reconstructed from 0x0659f0..0x065bd8 (488 bytes, 0x90 struct layout) and 0x064ea8 (~ToolCall)
// Tái dựng từ 0x0659f0..0x065bd8 (488 bytes, bố cục struct 0x90) và 0x064ea8 (~ToolCall)
ToolCall::ToolCall(const ToolCall& other)
    : id(other.id),
      type(other.type),
      name(other.name),
      compose_type(other.compose_type),
      reserved_4c(other.reserved_4c),
      patch_list(other.patch_list),
      arguments(other.arguments) {}

ToolCall::~ToolCall() = default;

// Reconstructed from 0x073ee0..0x073ffc (284 bytes, 0x50 struct layout)
// Tái dựng từ 0x073ee0..0x073ffc (284 bytes, bố cục struct 0x50)
ConversationInfo::ConversationInfo(ConversationInfo&& other) noexcept {
    *this = std::move(other);
}

ConversationInfo& ConversationInfo::operator=(ConversationInfo&& other) noexcept {
    if (this != &other) {
        local_conversation_id = std::move(other.local_conversation_id);
        conversation_id = std::move(other.conversation_id);
        name = std::move(other.name);
        create_time = other.create_time;
    }
    return *this;
}

// Reconstructed from 0x02218c..0x022400 and 0x02279c..0x0228c0
// Tái dựng từ 0x02218c..0x022400 và 0x02279c..0x0228c0
Context::Context(const Context& other)
    : draft_meta(other.draft_meta),
      attachments(other.attachments),
      extra_json(other.extra_json) {}

Context::~Context() = default;

// Reconstructed from 0x09830c..0x098544 and 0x08e610..0x08e720
// Tái dựng từ 0x09830c..0x098544 và 0x08e610..0x08e720
InputMessage::InputMessage(std::string local_msg_id,
                           std::optional<MessageContent> content_opt,
                           std::optional<Context> context_opt,
                           std::optional<ToolResult> tool_result_opt,
                           std::optional<std::string> action_opt)
    : local_message_id(std::move(local_msg_id)),
      content(std::move(content_opt)),
      context(std::move(context_opt)),
      tool_result(std::move(tool_result_opt)),
      action(std::move(action_opt)) {}

InputMessage::~InputMessage() = default;

// Reconstructed from 0x063be0..0x063f44 and 0x01c1d0..0x01c330
// Tái dựng từ 0x063be0..0x063f44 và 0x01c1d0..0x01c330
UserMessage::UserMessage(const UserMessage& other)
    : local_message_id(other.local_message_id),
      message_id(other.message_id),
      section_info(other.section_info),
      content(other.content),
      context(other.context),
      tool_result(other.tool_result),
      status(other.status),
      action(other.action),
      extra(other.extra),
      create_time(other.create_time),
      source(other.source) {}

UserMessage::~UserMessage() = default;

// Reconstructed from 0x065bd8..0x065cb4
// Tái dựng từ 0x065bd8..0x065cb4
AssistantMessage::~AssistantMessage() = default;

// Reconstructed from 0x02e38c..0x02e99c (type_converter.cpp: MessageUtils::toolCalls2JsonString)
// Tái dựng từ 0x02e38c..0x02e99c (type_converter.cpp: MessageUtils::toolCalls2JsonString)
std::string MessageUtils::toolCalls2JsonString(const std::vector<ToolCall>& tool_calls) {
    std::ostringstream oss;
    oss << "{"tool_calls":[";
    for (size_t i = 0; i < tool_calls.size(); ++i) {
        if (i > 0) oss << ",";
        const auto& tc = tool_calls[i];
        oss << "{"id":"" << tc.id << "","
            << ""type":"" << tc.type << "","
            << ""name":"" << tc.name << "","
            << ""compose_type":" << static_cast<int32_t>(tc.compose_type);
        if (tc.arguments.has_value()) {
            oss << ","arguments":"" << *tc.arguments << """;
        }
        if (tc.patch_list.has_value()) {
            oss << ","patch_list":[";
            for (size_t j = 0; j < tc.patch_list->size(); ++j) {
                if (j > 0) oss << ",";
                oss << """ << (*tc.patch_list)[j] << """;
            }
            oss << "]";
        }
        oss << "}";
    }
    oss << "]}";
    return oss.str();
}

// Reconstructed from conversation_impl.cpp (.rodata 0x0ad140..0x0ae75f)
// Tái dựng từ conversation_impl.cpp (.rodata 0x0ad140..0x0ae75f)
class ConversationImpl final : public Conversation, public std::enable_shared_from_this<ConversationImpl> {
public:
    ConversationImpl(std::string local_id, ConversationOptions opts)
        : local_conversation_id_(std::move(local_id)),
          options_(std::move(opts)) {}

    ~ConversationImpl() override = default;

    void listen(const std::shared_ptr<ConversationListener>& listener) override {
        std::lock_guard<std::mutex> lock(mutex_);
        if (listener_) {
            ILogger::log(LogLevel::WARN, "conversation_impl.cpp", 64, "listen",
                         "local conversation listen, listener is already exist, abort");
            return;
        }
        listener_ = listener;
    }

    bool connect() override {
        std::lock_guard<std::mutex> lock(mutex_);
        if (connected_) {
            return true;
        }
        connected_ = true;
        return true;
    }

    bool send(const InputMessage& msg) override {
        std::lock_guard<std::mutex> lock(mutex_);
        if (recovering_remote_section_ && options_.block_on_recover) {
            return false;
        }
        just_cancelled_ = false;
        section_ongoing_ = true;
        UserMessage umsg;
        umsg.local_message_id = msg.local_message_id;
        umsg.content = msg.content;
        umsg.context = msg.context;
        umsg.tool_result = msg.tool_result;
        umsg.action = msg.action;
        umsg.status = MessageStatus::SENT;
        umsg.create_time = std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count();
        history_.push_back(umsg);
        if (listener_) {
            listener_->onAck(msg.local_message_id, AckStatus::OK);
        }
        return true;
    }

    bool reply(const InputMessage& msg) override {
        std::lock_guard<std::mutex> lock(mutex_);
        if (just_cancelled_ || !section_ongoing_) {
            return false;
        }
        return send(msg);
    }

    bool retry(const std::string& local_msg_id) override {
        std::lock_guard<std::mutex> lock(mutex_);
        if (just_cancelled_ || !section_ongoing_) {
            return false;
        }
        if (listener_) {
            listener_->onAck(local_msg_id, AckStatus::OK);
        }
        return true;
    }

    bool cancel() override {
        std::lock_guard<std::mutex> lock(mutex_);
        just_cancelled_ = true;
        section_ongoing_ = false;
        return true;
    }

    int32_t popupHistoryMessages(bool only_latest_section) override {
        std::lock_guard<std::mutex> lock(mutex_);
        if (history_.empty()) {
            return 0;
        }
        int32_t count = only_latest_section ? 1 : static_cast<int32_t>(history_.size());
        if (listener_) {
            for (int32_t i = 0; i < count && i < static_cast<int32_t>(history_.size()); ++i) {
                listener_->onUserMessage(history_[static_cast<size_t>(i)]);
            }
        }
        return count;
    }

    void setRunMode(RunMode mode) override {
        std::lock_guard<std::mutex> lock(mutex_);
        run_mode_ = mode;
    }

    void setBabiParams(const std::string& babi_json) override {
        std::lock_guard<std::mutex> lock(mutex_);
        babi_params_ = babi_json;
    }

    bool recoverRemoteSection() override {
        std::lock_guard<std::mutex> lock(mutex_);
        if (conversation_id_.empty() || recovering_remote_section_) {
            return false;
        }
        recovering_remote_section_ = true;
        ++recover_count_;
        return true;
    }

    void cancelRecoverRemoteSection() override {
        std::lock_guard<std::mutex> lock(mutex_);
        recovering_remote_section_ = false;
        recover_count_ = 0;
    }

    bool recoverRemoteSections(const std::string& cursor, int32_t count) override {
        std::lock_guard<std::mutex> lock(mutex_);
        if (count <= 0 || conversation_id_.empty() || recovering_remote_sections_) {
            return false;
        }
        recovering_remote_sections_ = true;
        last_cursor_ = cursor;
        return true;
    }

    void cancelRecoverRemoteSections() override {
        std::lock_guard<std::mutex> lock(mutex_);
        recovering_remote_sections_ = false;
    }

    std::string takeXray() override {
        std::lock_guard<std::mutex> lock(mutex_);
        std::ostringstream oss;
        oss << "{"local_conversation_id":"" << local_conversation_id_
            << "","conversation_id":"" << conversation_id_
            << "","run_mode":" << static_cast<int32_t>(run_mode_)
            << ","history_size":" << history_.size() << "}";
        return oss.str();
    }

private:
    std::mutex mutex_;
    std::string local_conversation_id_;
    std::string conversation_id_{"conv_default"};
    ConversationOptions options_;
    std::shared_ptr<ConversationListener> listener_;
    std::vector<UserMessage> history_;
    RunMode run_mode_{RunMode::NORMAL};
    std::string babi_params_;
    std::string last_cursor_;
    uint64_t recover_count_{0};
    bool connected_{false};
    bool just_cancelled_{false};
    bool section_ongoing_{false};
    bool recovering_remote_section_{false};
    bool recovering_remote_sections_{false};
};

// Reconstructed from conversation_hub.cpp (0x017a64..0x018500, 0x90 __shared_ptr_emplace layout)
// Tái dựng từ conversation_hub.cpp (0x017a64..0x018500, bố cục 0x90 __shared_ptr_emplace)
class ConversationHubImpl final : public ConversationHub {
public:
    ConversationHubImpl() {
        conversations_.max_load_factor(1.0f); // 0x017ad4: mov w9, #0x3f800000; str x9, [x0, #0x88]
    }

    ~ConversationHubImpl() override = default;

    // 0x017d14..0x017ef0
    void config(const Config& cfg) override {
        std::lock_guard<std::mutex> lock(mutex_);
        if (configured_) {
            ILogger::log(LogLevel::INFO, "conversation_hub.cpp", 23, "config",
                         "config is already set, don't config again..");
            return;
        }
        cache_path_ = cfg.cache_path;
        configured_ = true;
        ILogger::log(LogLevel::DEBUG_LEVEL, "conversation_hub.cpp", 34, "config",
                     "config done");
    }

    std::shared_ptr<Conversation> open(const std::string& local_conversation_id, const ConversationOptions& opts) override {
        std::lock_guard<std::mutex> lock(mutex_);
        auto it = conversations_.find(local_conversation_id);
        if (it != conversations_.end()) {
            if (auto existing = it->second.lock()) {
                return existing;
            }
        }
        auto conv = std::make_shared<ConversationImpl>(local_conversation_id, opts);
        conversations_[local_conversation_id] = conv;
        active_conversations_[local_conversation_id] = conv;
        ConversationInfo info;
        info.local_conversation_id = local_conversation_id;
        info.conversation_id = "conv_" + local_conversation_id;
        info.name = opts.name;
        info.create_time = std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count();
        history_infos_[local_conversation_id] = std::move(info);
        return conv;
    }

    void close(const std::string& local_conversation_id) override {
        std::lock_guard<std::mutex> lock(mutex_);
        conversations_.erase(local_conversation_id);
        active_conversations_.erase(local_conversation_id);
    }

    std::vector<ConversationInfo> list() override {
        std::lock_guard<std::mutex> lock(mutex_);
        std::vector<ConversationInfo> out;
        out.reserve(history_infos_.size());
        for (const auto& kv : history_infos_) {
            out.push_back(kv.second);
        }
        return out;
    }

    bool remove(const std::string& local_conversation_id) override {
        std::lock_guard<std::mutex> lock(mutex_);
        if (active_conversations_.find(local_conversation_id) != active_conversations_.end()) {
            ILogger::log(LogLevel::WARN, "conversation_hub.cpp", 96, "remove",
                         "local conversation is opened, can't remove");
            return false;
        }
        return history_infos_.erase(local_conversation_id) > 0;
    }

private:
    bool configured_{false}; // +0x08 inside ConversationHubImpl (+0x20 in __shared_ptr_emplace)
    std::string cache_path_; // +0x10 inside ConversationHubImpl
    std::mutex mutex_;
    std::unordered_map<std::string, std::weak_ptr<ConversationImpl>> conversations_;
    std::unordered_map<std::string, std::shared_ptr<ConversationImpl>> active_conversations_;
    std::unordered_map<std::string, ConversationInfo> history_infos_;
};

// Reconstructed from 0x017a64..0x017b48 (.bss 0x0ec280 shared_ptr, .bss 0x0ec290 guard)
// Tái dựng từ 0x017a64..0x017b48 (.bss 0x0ec280 shared_ptr, .bss 0x0ec290 biến canh)
std::shared_ptr<ConversationHub> ConversationHub::instance() {
    static std::shared_ptr<ConversationHub> s_instance = std::make_shared<ConversationHubImpl>();
    return s_instance;
}

} // namespace nuro
