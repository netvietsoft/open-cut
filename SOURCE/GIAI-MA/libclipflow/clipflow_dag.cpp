// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libclipflow.so (ByteDance Vega ClipFlow DAG Task & Agent Engine)
// File: clipflow_dag.cpp
// Description: Directed Acyclic Graph (DAG) TaskGrapher Engine Implementation
//              ARM64 Parity: opcodes 0x39e13c, 0x39e808, 0x3a2c58
// ===================================================================================

#include "clipflow_dag.h"
#include <algorithm>
#include <queue>

namespace clipflow {

// ===================================================================================
// Constructor & Destructor / Khởi tạo & Hủy
// ===================================================================================

TaskGrapher::TaskGrapher()
    : m_is_built(false),
      m_is_cancelled(false)
{
}

TaskGrapher::~TaskGrapher() {
    cancelAll();
}

void TaskGrapher::reset() {
    std::lock_guard<std::mutex> lock(m_graph_mutex);
    m_tasks.clear();
    m_adj_list.clear();
    m_in_edges.clear();
    m_in_degree.clear();
    m_task_states.clear();
    m_is_built = false;
    m_is_cancelled = false;
}

// ===================================================================================
// Graph Construction & Dependency Setup / Xây dựng đồ thị & Thiết lập phụ thuộc
// ===================================================================================

bool TaskGrapher::addTask(const std::shared_ptr<IClipFlowTask>& task) {
    if (!task) return false;

    std::lock_guard<std::mutex> lock(m_graph_mutex);
    const std::string& id = task->getTaskId();

    if (m_tasks.find(id) != m_tasks.end()) {
        return false; // Trùng lặp Task ID
    }

    m_tasks[id] = task;
    m_task_states[id] = ClipFlowTaskExecuteState::IDLE;
    if (m_in_degree.find(id) == m_in_degree.end()) {
        m_in_degree[id] = 0;
    }

    m_is_built = false;
    return true;
}

bool TaskGrapher::addDependency(const std::string& parent_id, const std::string& child_id) {
    std::lock_guard<std::mutex> lock(m_graph_mutex);

    if (m_tasks.find(parent_id) == m_tasks.end() || m_tasks.find(child_id) == m_tasks.end()) {
        return false; // Một trong hai node chưa được thêm vào đồ thị
    }

    // Kiểm tra không thêm phụ thuộc trùng lặp
    auto& children = m_adj_list[parent_id];
    if (std::find(children.begin(), children.end(), child_id) != children.end()) {
        return true;
    }

    children.push_back(child_id);
    m_in_edges[child_id].push_back(parent_id);
    m_in_degree[child_id]++;

    m_is_built = false;
    return true;
}

bool TaskGrapher::hasCycle() const {
    std::lock_guard<std::mutex> lock(m_graph_mutex);

    // Thuật toán Kahn kiểm tra chu trình đồ thị có hướng (Cycle Detection via In-degree)
    std::unordered_map<std::string, int32_t> in_deg = m_in_degree;
    std::queue<std::string> zero_in_degree_nodes;

    for (const auto& [node_id, deg] : in_deg) {
        if (deg == 0) {
            zero_in_degree_nodes.push(node_id);
        }
    }

    size_t visited_count = 0;
    while (!zero_in_degree_nodes.empty()) {
        std::string curr = zero_in_degree_nodes.front();
        zero_in_degree_nodes.pop();
        visited_count++;

        auto it = m_adj_list.find(curr);
        if (it != m_adj_list.end()) {
            for (const auto& child : it->second) {
                in_deg[child]--;
                if (in_deg[child] == 0) {
                    zero_in_degree_nodes.push(child);
                }
            }
        }
    }

    // Nếu số node duyệt được nhỏ hơn tổng số node -> có chu trình (Cycle detected)
    return visited_count != m_tasks.size();
}

bool TaskGrapher::buildGraph() {
    std::lock_guard<std::mutex> lock(m_graph_mutex);

    if (hasCycle()) {
        return false; // Đồ thị chứa chu trình, không hợp lệ theo chuẩn DAG
    }

    m_is_built = true;
    return true;
}

std::vector<std::vector<std::string>> TaskGrapher::getExecutionWaves() const {
    std::lock_guard<std::mutex> lock(m_graph_mutex);

    std::vector<std::vector<std::string>> waves;
    if (m_tasks.empty()) return waves;

    std::unordered_map<std::string, int32_t> in_deg = m_in_degree;
    std::vector<std::string> current_wave;

    for (const auto& [node_id, deg] : in_deg) {
        if (deg == 0) {
            current_wave.push_back(node_id);
        }
    }

    while (!current_wave.empty()) {
        waves.push_back(current_wave);
        std::vector<std::string> next_wave;

        for (const auto& node_id : current_wave) {
            auto it = m_adj_list.find(node_id);
            if (it != m_adj_list.end()) {
                for (const auto& child : it->second) {
                    in_deg[child]--;
                    if (in_deg[child] == 0) {
                        next_wave.push_back(child);
                    }
                }
            }
        }

        current_wave = std::move(next_wave);
    }

    return waves;
}

// ===================================================================================
// Task & Graph Execution / Thực thi tác vụ & Toàn bộ đồ thị
// ===================================================================================

ClipFlowTaskExecuteState TaskGrapher::executeTask(const std::shared_ptr<IClipFlowTask>& task) {
    if (!task) return ClipFlowTaskExecuteState::FAILED;

    const std::string& id = task->getTaskId();

    {
        std::lock_guard<std::mutex> lock(m_graph_mutex);
        if (m_is_cancelled.load()) {
            m_task_states[id] = ClipFlowTaskExecuteState::CANCELLED;
            return ClipFlowTaskExecuteState::CANCELLED;
        }
        m_task_states[id] = ClipFlowTaskExecuteState::RUNNING;
    }

    // Gọi hàm thực thi ảo (vtable 0x100 dispatch khớp opcode 0x39e844: blr x9)
    // Execute task via virtual dispatch
    ClipFlowTaskExecuteState result = task->execute();

    // Đối soát mã hủy: nếu w0 == -4 (cmn w0, #4 khớp opcode 0x39e848), xem là CANCELLED
    if (static_cast<int32_t>(result) == -4) {
        result = ClipFlowTaskExecuteState::CANCELLED;
    }

    {
        std::lock_guard<std::mutex> lock(m_graph_mutex);
        m_task_states[id] = result;
    }

    return result;
}

bool TaskGrapher::executeGraph() {
    if (!m_is_built) {
        if (!buildGraph()) return false;
    }

    m_is_cancelled.store(false);
    auto waves = getExecutionWaves();

    for (const auto& wave : waves) {
        if (m_is_cancelled.load()) {
            return false;
        }

        // Thực thi các tác vụ trong cùng một wave độc lập
        for (const auto& node_id : wave) {
            std::shared_ptr<IClipFlowTask> task = nullptr;
            {
                std::lock_guard<std::mutex> lock(m_graph_mutex);
                auto it = m_tasks.find(node_id);
                if (it != m_tasks.end()) {
                    task = it->second;
                }
            }

            if (!task) continue;

            // Kiểm tra xem tất cả các node cha có thành công hay không
            bool parents_succeeded = true;
            {
                std::lock_guard<std::mutex> lock(m_graph_mutex);
                auto it_parents = m_in_edges.find(node_id);
                if (it_parents != m_in_edges.end()) {
                    for (const auto& parent_id : it_parents->second) {
                        if (m_task_states[parent_id] != ClipFlowTaskExecuteState::SUCCESS) {
                            parents_succeeded = false;
                            break;
                        }
                    }
                }
            }

            if (!parents_succeeded) {
                // Node cha thất bại hoặc bị hủy -> truyền trạng thái hủy đến node con này
                std::lock_guard<std::mutex> lock(m_graph_mutex);
                m_task_states[node_id] = ClipFlowTaskExecuteState::CANCELLED;
                continue;
            }

            // Thực thi tác vụ
            ClipFlowTaskExecuteState st = executeTask(task);
            if (st != ClipFlowTaskExecuteState::SUCCESS) {
                // Khi một tác vụ thất bại, các nhánh con sẽ tự động bị hủy ở các wave sau
            }
        }
    }

    // Kiểm tra xem tất cả các tác vụ đã hoàn thành thành công hay không
    std::lock_guard<std::mutex> lock(m_graph_mutex);
    for (const auto& [id, st] : m_task_states) {
        if (st != ClipFlowTaskExecuteState::SUCCESS) {
            return false;
        }
    }

    return true;
}

bool TaskGrapher::cancelTask(const std::string& task_id) {
    std::lock_guard<std::mutex> lock(m_graph_mutex);

    auto it = m_tasks.find(task_id);
    if (it == m_tasks.end()) return false;

    it->second->cancel();
    m_task_states[task_id] = ClipFlowTaskExecuteState::CANCELLED;

    // Lan truyền trạng thái hủy cho tất cả các nút con phụ thuộc (Cancellation Propagation)
    std::queue<std::string> to_cancel;
    to_cancel.push(task_id);

    while (!to_cancel.empty()) {
        std::string curr = to_cancel.front();
        to_cancel.pop();

        auto it_adj = m_adj_list.find(curr);
        if (it_adj != m_adj_list.end()) {
            for (const auto& child_id : it_adj->second) {
                if (m_task_states[child_id] != ClipFlowTaskExecuteState::CANCELLED) {
                    m_task_states[child_id] = ClipFlowTaskExecuteState::CANCELLED;
                    auto it_child = m_tasks.find(child_id);
                    if (it_child != m_tasks.end()) {
                        it_child->second->cancel();
                    }
                    to_cancel.push(child_id);
                }
            }
        }
    }

    return true;
}

void TaskGrapher::cancelAll() {
    m_is_cancelled.store(true);
    std::lock_guard<std::mutex> lock(m_graph_mutex);

    for (auto& [id, task] : m_tasks) {
        if (task) task->cancel();
        m_task_states[id] = ClipFlowTaskExecuteState::CANCELLED;
    }
}

size_t TaskGrapher::getTaskCount() const {
    std::lock_guard<std::mutex> lock(m_graph_mutex);
    return m_tasks.size();
}

size_t TaskGrapher::getCompletedCount() const {
    std::lock_guard<std::mutex> lock(m_graph_mutex);
    size_t count = 0;
    for (const auto& [id, st] : m_task_states) {
        if (st == ClipFlowTaskExecuteState::SUCCESS) {
            count++;
        }
    }
    return count;
}

ClipFlowTaskExecuteState TaskGrapher::getTaskState(const std::string& task_id) const {
    std::lock_guard<std::mutex> lock(m_graph_mutex);
    auto it = m_task_states.find(task_id);
    if (it != m_task_states.end()) {
        return it->second;
    }
    return ClipFlowTaskExecuteState::IDLE;
}

} // namespace clipflow
