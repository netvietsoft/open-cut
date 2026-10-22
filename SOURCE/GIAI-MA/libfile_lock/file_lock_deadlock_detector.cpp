/**
 * @file file_lock_deadlock_detector.cpp
 * @brief ByteDance GeckoX FileLock Deadlock Prevention & Directed Graph Cycle Detector Implementation.
 *        Hiện thực mã nguồn C++ phát hiện chu trình bế tắc cho GeckoX FileLock.
 */

#include "file_lock_deadlock_detector.h"
#include <algorithm>

namespace nextai {
namespace opencut {
namespace filelock {

DeadlockDetector& DeadlockDetector::getInstance() {
    static DeadlockDetector s_instance;
    return s_instance;
}

void DeadlockDetector::addWaitEdge(uint64_t waitingOwner, uint64_t holdingOwner, int fd, int segment) {
    if (waitingOwner == holdingOwner) return;
    std::lock_guard<std::mutex> lock(m_mutex);
    m_adjacencyList[waitingOwner].insert(holdingOwner);
}

void DeadlockDetector::removeWaitEdge(uint64_t waitingOwner, int fd, int segment) {
    std::lock_guard<std::mutex> lock(m_mutex);
    auto it = m_segmentOwners.find(fd);
    if (it != m_segmentOwners.end()) {
        auto segIt = it->second.find(segment);
        if (segIt != it->second.end()) {
            uint64_t holdingOwner = segIt->second;
            auto adjIt = m_adjacencyList.find(waitingOwner);
            if (adjIt != m_adjacencyList.end()) {
                adjIt->second.erase(holdingOwner);
                if (adjIt->second.empty()) {
                    m_adjacencyList.erase(adjIt);
                }
            }
        }
    }
}

void DeadlockDetector::registerOwnership(uint64_t owner, int fd, int segment) {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_segmentOwners[fd][segment] = owner;
}

void DeadlockDetector::releaseOwnership(uint64_t owner, int fd, int segment) {
    std::lock_guard<std::mutex> lock(m_mutex);
    auto it = m_segmentOwners.find(fd);
    if (it != m_segmentOwners.end()) {
        auto segIt = it->second.find(segment);
        if (segIt != it->second.end() && segIt->second == owner) {
            it->second.erase(segIt);
            if (it->second.empty()) {
                m_segmentOwners.erase(it);
            }
        }
    }
}

bool DeadlockDetector::wouldCauseDeadlock(uint64_t waitingOwner, uint64_t holdingOwner) const {
    if (waitingOwner == holdingOwner) return true;
    std::lock_guard<std::mutex> lock(m_mutex);

    // If holdingOwner can reach waitingOwner in the graph, adding waitingOwner -> holdingOwner creates a cycle
    // Nếu holdingOwner có thể đi tới waitingOwner, việc thêm cạnh waitingOwner -> holdingOwner sẽ tạo chu trình
    std::unordered_set<uint64_t> visited;
    std::vector<uint64_t> queue;
    queue.push_back(holdingOwner);
    visited.insert(holdingOwner);

    while (!queue.empty()) {
        uint64_t curr = queue.back();
        queue.pop_back();

        if (curr == waitingOwner) {
            return true;
        }

        auto it = m_adjacencyList.find(curr);
        if (it != m_adjacencyList.end()) {
            for (uint64_t neighbor : it->second) {
                if (neighbor == waitingOwner) {
                    return true;
                }
                if (visited.find(neighbor) == visited.end()) {
                    visited.insert(neighbor);
                    queue.push_back(neighbor);
                }
            }
        }
    }

    return false;
}

bool DeadlockDetector::dfsCheck(
    uint64_t current,
    std::unordered_set<uint64_t>& visited,
    std::unordered_set<uint64_t>& recursionStack,
    std::vector<uint64_t>& cyclePath
) const {
    visited.insert(current);
    recursionStack.insert(current);
    cyclePath.push_back(current);

    auto it = m_adjacencyList.find(current);
    if (it != m_adjacencyList.end()) {
        for (uint64_t neighbor : it->second) {
            if (recursionStack.find(neighbor) != recursionStack.end()) {
                cyclePath.push_back(neighbor);
                return true;
            }
            if (visited.find(neighbor) == visited.end()) {
                if (dfsCheck(neighbor, visited, recursionStack, cyclePath)) {
                    return true;
                }
            }
        }
    }

    recursionStack.erase(current);
    cyclePath.pop_back();
    return false;
}

bool DeadlockDetector::hasDeadlockCycle(std::vector<uint64_t>& outCycleNodes) const {
    std::lock_guard<std::mutex> lock(m_mutex);
    std::unordered_set<uint64_t> visited;
    std::unordered_set<uint64_t> recursionStack;
    outCycleNodes.clear();

    for (const auto& kv : m_adjacencyList) {
        uint64_t startNode = kv.first;
        if (visited.find(startNode) == visited.end()) {
            if (dfsCheck(startNode, visited, recursionStack, outCycleNodes)) {
                return true;
            }
        }
    }

    return false;
}

void DeadlockDetector::clear() {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_adjacencyList.clear();
    m_segmentOwners.clear();
}

} // namespace filelock
} // namespace opencut
} // namespace nextai
