// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libmiddleware.so (ByteDance Retouch & CrossPlatform NLE Middleware)
// File: middleware_batch_push.h
// Description: Atomic Batch Push and Undo/Redo Transaction Manager
//              Reverse-engineered from ARM64 opcodes 0x12fc5e8, 0x12fc620
// ===================================================================================

#pragma once

#include "middleware_types.h"
#include <mutex>
#include <vector>
#include <functional>

namespace retouch::middleware {

struct HistoryAction {
    std::string name;
    std::function<void()> undo_func;
    std::function<void()> redo_func;
};

/**
 * @brief Bộ quản lý giao dịch thao tác nguyên tử BatchPush (Undo/Redo History)
 * Khôi phục từ RetouchContext offset 0x138 (opcode 0x12fc604..0x12fc60c)
 */
class BatchPushManager {
public:
    BatchPushManager();
    ~BatchPushManager() = default;

    /// Mở một phiên giao dịch thao tác hàng loạt (Khớp opcode 0x12fc5e8: nativeBeginBatchPush)
    int32_t beginBatchPush();

    /// Đóng và cam kết phiên giao dịch thao tác (Khớp opcode 0x12fc620: nativeEndBatchPush)
    bool endBatchPush();

    /// Đăng ký một hành động nguyên tử vào giao dịch hiện tại
    void recordAction(std::string name, std::function<void()> undo_func, std::function<void()> redo_func);

    /// Hoàn tác thao tác trước đó (Undo)
    bool undo();

    /// Làm lại thao tác vừa hoàn tác (Redo)
    bool redo();

    bool canUndo() const;
    bool canRedo() const;
    size_t getUndoCount() const;
    size_t getRedoCount() const;
    bool isBatchOpen() const;

    void clearHistory();

private:
    mutable std::mutex m_batch_mutex;
    int32_t m_next_transaction_id;
    bool m_is_batch_open;
    std::vector<HistoryAction> m_current_batch_actions;

    std::vector<std::vector<HistoryAction>> m_undo_stack;
    std::vector<std::vector<HistoryAction>> m_redo_stack;
};

} // namespace retouch::middleware
