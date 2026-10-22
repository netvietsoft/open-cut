/**
 * @file file_lock_pgl_deadlock.cpp
 * @brief ByteDance Pangle / OpenVK GeckoX FileLock Deadlock Prevention Implementation.
 *        Hiện thực thuật toán đồ thị có hướng phát hiện bế tắc khóa tệp Pangle GeckoX.
 */

#include "file_lock_pgl_deadlock.h"
#include <algorithm>

namespace nextai {
namespace opencut {
namespace filelock_pgl {

PglDeadlockDetector& PglDeadlockDetector::getInstance() {
    static PglDeadlockDetector s_instance;
    return s_instance;
}

void PglDeadlockDetector::addWaitEdge(uint64_t waitingOwner, uint64_t holdingOwner, int fd, int segment) {
    if (waitingOwner == holdingOwner) {
        return;
    }
    std::lock_guard<std::mutex> lock(m_mutex);
    m_adjacencyList[waitingOwner].insert(holdingOwner);
}

void PglDeadlockDetector::removeWaitEdge(uint64_t waitingOwner, int fd, int segment) {
    std::lock_guard<std::mutex> lock(m_mutex);
    auto it = m_adjacencyList.find(waitingOwner);
    if (it != m_adjacencyList.end()) {
        m_adjacencyList.erase(it);
    }
}

void PglDeadlockDetector::registerOwnership(uint64_t owner, int fd, int segment) {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_segmentOwners[fd][segment] = owner;
}

void PglDeadlockDetector::releaseOwnership(uint64_t owner, int fd, int segment) {
    std::lock_guard<std::mutex> lock(m_mutex);
    auto itFd = m_segmentOwners.find(fd);
    if (itFd != m_segmentOwners.end()) {
        itFd->second.erase(segment);
        if (itFd->second.empty()) {
            m_segmentOwners.erase(itFd);
        }
    }
}

bool PglDeadlockDetector::wouldCauseDeadlock(uint64_t waitingOwner, uint64_t holdingOwner) const {
    if (waitingOwner == holdingOwner) {
        return true;
    }

    std::lock_guard<std::mutex> lock(m_mutex);
    // Path checking: does holdingOwner already wait for waitingOwner directly or indirectly?
    std::unordered_set<uint64_t> visited;
    std::vector<uint64_t> queue;
    queue.push_back(holdingOwner);
    visited.insert(holdingOwner);

    while (!queue.empty()) {
        uint64_t curr = queue.back();
        queue.pop_back();

        auto it = m_adjacencyList.find(curr);
        if (it != m_adjacencyList.end()) {
            for (uint64_t nextOwner : it->second) {
                if (nextOwner == waitingOwner) {
                    return true; // Cycle would be formed!
                }
                if (visited.find(nextOwner) == visited.end()) {
                    visited.insert(nextOwner);
                    queue.push_back(nextOwner);
                }
            }
        }
    }
    return false;
}

bool PglDeadlockDetector::dfsCheck(
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
                return true; // Cycle detected
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

bool PglDeadlockDetector::hasDeadlockCycle(std::vector<uint64_t>& outCycleNodes) const {
    std::lock_guard<std::mutex> lock(m_mutex);
    std::unordered_set<uint64_t> visited;
    std::unordered_set<uint64_t> recursionStack;
    outCycleNodes.clear();

    for (const auto& pair : m_adjacencyList) {
        uint64_t node = pair.first;
        if (visited.find(node) == visited.end()) {
            if (dfsCheck(node, visited, recursionStack, outCycleNodes)) {
                return true;
            }
        }
    }
    return false;
}

void PglDeadlockDetector::clear() {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_adjacencyList.clear();
    m_segmentOwners.clear();
}

} // namespace filelock_pgl
} // namespace opencut
} // namespace nextai
