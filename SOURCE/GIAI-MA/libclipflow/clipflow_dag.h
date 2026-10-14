// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libclipflow.so (ByteDance Vega ClipFlow DAG Task & Agent Engine)
// File: clipflow_dag.h
// Description: Directed Acyclic Graph (DAG) TaskGrapher Engine
//              Reverse-engineered from ARM64 opcodes 0x39e13c, 0x39e808, 0x3a2c58
// ===================================================================================

#pragma once

#include "clipflow_types.h"
#include <mutex>
#include <queue>
#include <atomic>

namespace clipflow {

/**
 * @brief Động cơ điều phối đồ thị tác vụ DAG (TaskGrapher Engine)
 * Xây dựng cây phụ thuộc, kiểm tra chu trình (Cycle Detection),
 * sắp xếp tô pô (Topological Sort) và thực thi song song các làn sóng tác vụ độc lập.
 */
class TaskGrapher {
public:
    TaskGrapher();
    virtual ~TaskGrapher();

    /// Thêm một tác vụ vào đồ thị (Khớp opcode 0x39e13c: TaskGrapher::addTask)
    bool addTask(const std::shared_ptr<IClipFlowTask>& task);

    /// Thiết lập quan hệ phụ thuộc: child_id phụ thuộc vào parent_id
    bool addDependency(const std::string& parent_id, const std::string& child_id);

    /// Xây dựng và tối ưu hóa đồ thị (Khớp opcode 0x3a2c58: BaseGrapher::buildGraph)
    bool buildGraph();

    /// Kiểm tra đồ thị có chứa chu trình bất hợp lệ hay không (Cycle Detection)
    bool hasCycle() const;

    /// Lấy danh sách các đợt thực thi song song theo thứ tự tô pô (Parallel Execution Waves)
    std::vector<std::vector<std::string>> getExecutionWaves() const;

    /// Thực thi một tác vụ đơn lẻ (Khớp opcode 0x39e808: TaskGrapher::executeTask)
    ClipFlowTaskExecuteState executeTask(const std::shared_ptr<IClipFlowTask>& task);

    /// Thực thi toàn bộ đồ thị tác vụ theo thứ tự phụ thuộc
    bool executeGraph();

    /// Hủy một tác vụ cụ thể và truyền tín hiệu hủy đến các nút con (Cancellation Propagation)
    bool cancelTask(const std::string& task_id);

    /// Hủy toàn bộ đồ thị
    void cancelAll();

    /// Đặt lại trạng thái đồ thị
    void reset();

    // Thống kê và kiểm tra trạng thái
    size_t getTaskCount() const;
    size_t getCompletedCount() const;
    ClipFlowTaskExecuteState getTaskState(const std::string& task_id) const;

private:
    mutable std::mutex m_graph_mutex;

    // Danh sách tác vụ theo ID
    std::unordered_map<std::string, std::shared_ptr<IClipFlowTask>> m_tasks;

    // Cấu trúc đồ thị DAG: kề tiến và kề lùi
    std::unordered_map<std::string, std::vector<std::string>> m_adj_list;    // parent -> list of children
    std::unordered_map<std::string, std::vector<std::string>> m_in_edges;    // child -> list of parents
    std::unordered_map<std::string, int32_t> m_in_degree;                    // số bậc vào

    // Trạng thái thực thi từng tác vụ
    std::unordered_map<std::string, ClipFlowTaskExecuteState> m_task_states;

    bool m_is_built;
    std::atomic<bool> m_is_cancelled;
};

} // namespace clipflow
