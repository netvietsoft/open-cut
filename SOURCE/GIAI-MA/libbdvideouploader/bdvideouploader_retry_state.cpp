/**
 * @file bdvideouploader_retry_state.cpp
 * @brief ByteDance Video Uploader - Exponential Backoff & Retry Implementations.
 *        Cài đặt chi tiết máy trạng thái thử lại và phân loại mã lỗi truyền dẫn.
 *
 * Rules: AGENTS.md Rule 12 (Bilingual EN/VN), Rule 14 & 20 (Zero stubs, exact binary parity).
 */

#include "bdvideouploader_retry_state.h"
#include <algorithm>

namespace com {
namespace ss {
namespace bduploader {

BDRetryStateMachine::BDRetryStateMachine(int32_t maxRetries, int32_t baseDelayMs)
    : mMaxRetries(std::max(0, maxRetries)),
      mBaseDelayMs(std::max(100, baseDelayMs)),
      mRetryCount(0) {}

void BDRetryStateMachine::reset() {
    mRetryCount = 0;
}

int32_t BDRetryStateMachine::calculateBackoffDelay(int32_t attempt) const {
    if (attempt <= 0) return 0;
    // Exponential formula: delay = base * 2^(attempt - 1), capped at 30,000 ms (30s)
    int64_t multiplier = 1LL << std::min(attempt - 1, 5);
    int64_t delay = static_cast<int64_t>(mBaseDelayMs) * multiplier;
    return static_cast<int32_t>(std::min<int64_t>(30000, delay));
}

BDRetryDecision BDRetryStateMachine::shouldRetryForError(
    int32_t httpCode, int32_t socketError, int32_t currentAttempt
) {
    BDRetryDecision decision;
    decision.shouldRetry = false;
    decision.delayMs = 0;
    decision.switchProtocolToQuic = false;

    if (currentAttempt >= mMaxRetries) {
        decision.reason = "Max retry attempts reached";
        return decision;
    }

    // 1. Check HTTP status code retryability
    bool retryableHttp = (httpCode == 408 || // Request Timeout
                          httpCode == 429 || // Too Many Requests
                          httpCode == 500 || // Internal Server Error
                          httpCode == 502 || // Bad Gateway
                          httpCode == 503 || // Service Unavailable
                          httpCode == 504);  // Gateway Timeout

    // 2. Check Socket Network Error codes
    // 1001: Connection reset, 1002: Connection refused, 1003: Socket timeout, 1004: Network down
    bool retryableSocket = (socketError > 0);

    if (retryableHttp || retryableSocket) {
        mRetryCount = currentAttempt + 1;
        decision.shouldRetry = true;
        decision.delayMs = calculateBackoffDelay(mRetryCount);

        if (retryableSocket) {
            decision.reason = "Socket network error: " + std::to_string(socketError);
            // Switch to xquic on repeated socket failures (opcode 0x012028 switch to xquic for 1001)
            if (socketError == 1001 || mRetryCount >= 2) {
                decision.switchProtocolToQuic = true;
            }
        } else {
            decision.reason = "Retryable HTTP status: " + std::to_string(httpCode);
        }
    } else {
        decision.reason = "Non-retryable status code: " + std::to_string(httpCode);
    }

    return decision;
}

int32_t BDRetryStateMachine::getRetryCount() const {
    return mRetryCount;
}

int32_t BDRetryStateMachine::getMaxRetries() const {
    return mMaxRetries;
}

void BDRetryStateMachine::setMaxRetries(int32_t maxRetries) {
    mMaxRetries = std::max(0, maxRetries);
}

} // namespace bduploader
} // namespace ss
} // namespace com
