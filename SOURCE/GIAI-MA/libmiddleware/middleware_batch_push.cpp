// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libmiddleware.so (ByteDance Retouch & CrossPlatform NLE Middleware)
// File: middleware_batch_push.cpp
// Description: Atomic Batch Push and Undo/Redo Transaction Manager Implementation
//              ARM64 Parity: opcodes 0x12fc5e8, 0x12fc620
// ===================================================================================

#include "middleware_batch_push.h"

namespace retouch::middleware {

BatchPushManager::BatchPushManager()
    : m_next_transaction_id(1),
      m_is_batch_open(false)
{
}

int32_t BatchPushManager::beginBatchPush() {
    // Khớp opcode 0x12fc5e8: nativeBeginBatchPush
    std::lock_guard<std::mutex> lock(m_batch_mutex);
    m_is_batch_open = true;
    m_current_batch_actions.clear();
    return m_next_transaction_id++;
}

bool BatchPushManager::endBatchPush() {
    // Khớp opcode 0x12fc620: nativeEndBatchPush
    std::lock_guard<std::mutex> lock(m_batch_mutex);
    if (!m_is_batch_open) return false;

    if (!m_current_batch_actions.empty()) {
        m_undo_stack.push_back(std::move(m_current_batch_actions));
        m_redo_stack.clear(); // Xóa redo stack khi có thao tác mới
    }

    m_current_batch_actions.clear();
    m_is_batch_open = false;
    return true;
}

void BatchPushManager::recordAction(
    std::string name,
    std::function<void()> undo_func,
    std::function<void()> redo_func)
{
    std::lock_guard<std::mutex> lock(m_batch_mutex);
    HistoryAction action;
    action.name = std::move(name);
    action.undo_func = std::move(undo_func);
    action.redo_func = std::move(redo_func);

    if (m_is_batch_open) {
        m_current_batch_actions.push_back(std::move(action));
    } else {
        // Thao tác đơn lẻ không nằm trong batch
        m_undo_stack.push_back({ std::move(action) });
        m_redo_stack.clear();
    }
}

bool BatchPushManager::undo() {
    std::lock_guard<std::mutex> lock(m_batch_mutex);
    if (m_undo_stack.empty() || m_is_batch_open) {
        return false;
    }

    auto batch = std::move(m_undo_stack.back());
    m_undo_stack.pop_back();

    // Thực thi hoàn tác theo thứ tự ngược lại (Reverse order)
    for (auto it = batch.rbegin(); it != batch.rend(); ++it) {
        if (it->undo_func) {
            it->undo_func();
        }
    }

    m_redo_stack.push_back(std::move(batch));
    return true;
}

bool BatchPushManager::redo() {
    std::lock_guard<std::mutex> lock(m_batch_mutex);
    if (m_redo_stack.empty() || m_is_batch_open) {
        return false;
    }

    auto batch = std::move(m_redo_stack.back());
    m_redo_stack.pop_back();

    // Thực thi làm lại theo thứ tự ban đầu (Forward order)
    for (auto& action : batch) {
        if (action.redo_func) {
            action.redo_func();
        }
    }

    m_undo_stack.push_back(std::move(batch));
    return true;
}

bool BatchPushManager::canUndo() const {
    std::lock_guard<std::mutex> lock(m_batch_mutex);
    return !m_undo_stack.empty() && !m_is_batch_open;
}

bool BatchPushManager::canRedo() const {
    std::lock_guard<std::mutex> lock(m_batch_mutex);
    return !m_redo_stack.empty() && !m_is_batch_open;
}

size_t BatchPushManager::getUndoCount() const {
    std::lock_guard<std::mutex> lock(m_batch_mutex);
    return m_undo_stack.size();
}

size_t BatchPushManager::getRedoCount() const {
    std::lock_guard<std::mutex> lock(m_batch_mutex);
    return m_redo_stack.size();
}

bool BatchPushManager::isBatchOpen() const {
    std::lock_guard<std::mutex> lock(m_batch_mutex);
    return m_is_batch_open;
}

void BatchPushManager::clearHistory() {
    std::lock_guard<std::mutex> lock(m_batch_mutex);
    m_undo_stack.clear();
    m_redo_stack.clear();
    m_current_batch_actions.clear();
    m_is_batch_open = false;
}

} // namespace retouch::middleware
