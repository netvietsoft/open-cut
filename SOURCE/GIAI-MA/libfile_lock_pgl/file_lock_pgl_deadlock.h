/**
 * @file file_lock_pgl_deadlock.h
 * @brief ByteDance Pangle / OpenVK GeckoX FileLock Deadlock Prevention & Directed Graph Cycle Detector.
 *        Bộ phát hiện bế tắc (deadlock) và thuật toán đồ thị có hướng cho Pangle OpenVK GeckoX FileLock.
 *
 * Implements Tarjan / DFS cycle detection on wait-for graphs across threads and processes.
 */

#ifndef GECKOX_FILE_LOCK_PGL_DEADLOCK_H
#define GECKOX_FILE_LOCK_PGL_DEADLOCK_H

#include "file_lock_pgl_types.h"
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <mutex>
#include <chrono>

namespace nextai {
namespace opencut {
namespace filelock_pgl {

/**
 * @brief Wait-for Graph Node representing a Thread/Process holding or requesting a Lock
 *        Đỉnh đồ thị biểu diễn luồng hoặc tiến trình đang nắm giữ hoặc yêu cầu khóa
 */
struct PglLockWaitNode {
    uint64_t ownerId;           ///< Thread/Process identifier / Định danh luồng/tiến trình
    int targetFd;               ///< Target file descriptor / File descriptor mục tiêu
    int segment;                ///< Segment index (-1 for full file) / Vị trí phân đoạn
    std::chrono::system_clock::time_point requestTime; ///< Timestamp / Thời điểm yêu cầu
};

/**
 * @brief Deadlock Cycle Detection Engine for Pangle
 *        Động cơ phát hiện chu trình bế tắc thời gian thực cho Pangle
 */
class PglDeadlockDetector {
public:
    static PglDeadlockDetector& getInstance();

    void addWaitEdge(uint64_t waitingOwner, uint64_t holdingOwner, int fd, int segment);
    void removeWaitEdge(uint64_t waitingOwner, int fd, int segment);
    void registerOwnership(uint64_t owner, int fd, int segment);
    void releaseOwnership(uint64_t owner, int fd, int segment);

    /**
     * @brief Check whether adding a dependency creates a cycle in the Wait-For Graph (WFG)
     *        Kiểm tra xem việc thêm cạnh chờ có tạo ra chu trình trong đồ thị WFG hay không
     */
    bool wouldCauseDeadlock(uint64_t waitingOwner, uint64_t holdingOwner) const;

    /**
     * @brief Detect existing deadlocks across all registered nodes using DFS
     *        Phát hiện chu trình bế tắc hiện hữu trên toàn bộ các đỉnh bằng DFS
     */
    bool hasDeadlockCycle(std::vector<uint64_t>& outCycleNodes) const;

    void clear();

private:
    PglDeadlockDetector() = default;
    ~PglDeadlockDetector() = default;

    bool dfsCheck(
        uint64_t current,
        std::unordered_set<uint64_t>& visited,
        std::unordered_set<uint64_t>& recursionStack,
        std::vector<uint64_t>& cyclePath
    ) const;

    mutable std::mutex m_mutex;
    std::unordered_map<uint64_t, std::unordered_set<uint64_t>> m_adjacencyList;
    std::unordered_map<int, std::unordered_map<int, uint64_t>> m_segmentOwners;
};

} // namespace filelock_pgl
} // namespace opencut
} // namespace nextai

#endif // GECKOX_FILE_LOCK_PGL_DEADLOCK_H
