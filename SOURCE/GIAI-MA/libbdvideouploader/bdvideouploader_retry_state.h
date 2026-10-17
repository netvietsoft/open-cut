/**
 * @file bdvideouploader_retry_state.h
 * @brief ByteDance Video Uploader - Exponential Backoff & Retry State Machine.
 *        Máy trạng thái xử lý lỗi mạng và giải thuật thử lại lùi lũy thừa.
 *
 * Rules: AGENTS.md Rule 12 (Bilingual EN/VN), Rule 14 & 20 (Zero stubs, exact binary parity).
 */

#ifndef BDVIDEOUPLOADER_RETRY_STATE_H
#define BDVIDEOUPLOADER_RETRY_STATE_H

#include "bdvideouploader_types.h"
#include <cstdint>
#include <string>

namespace com {
namespace ss {
namespace bduploader {

/**
 * @brief Retry Decision Result
 *        Kết quả quyết định có thử lại tác vụ hay không
 */
struct BDRetryDecision {
    bool shouldRetry;
    int32_t delayMs;
    std::string reason;
    bool switchProtocolToQuic;
};

/**
 * @brief Exponential Backoff & Error Retry Manager
 *        Bộ điều phối thử lại lùi lũy thừa khi gặp lỗi truyền dẫn
 */
class BDRetryStateMachine {
public:
    BDRetryStateMachine(int32_t maxRetries = BD_DEFAULT_RETRY_COUNT, int32_t baseDelayMs = 1000);

    void reset();

    /**
     * @brief Evaluates whether an HTTP status or socket error should trigger retry
     *        Đánh giá mã lỗi HTTP hoặc lỗi socket có được phép thử lại
     */
    BDRetryDecision shouldRetryForError(int32_t httpCode, int32_t socketError, int32_t currentAttempt);

    int32_t calculateBackoffDelay(int32_t attempt) const;
    int32_t getRetryCount() const;
    int32_t getMaxRetries() const;
    void setMaxRetries(int32_t maxRetries);

private:
    int32_t mMaxRetries;
    int32_t mBaseDelayMs;
    int32_t mRetryCount;
};

} // namespace bduploader
} // namespace ss
} // namespace com

#endif // BDVIDEOUPLOADER_RETRY_STATE_H
