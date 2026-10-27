/**
 * @file monitorcollector_rodata_tables.cpp
 * @brief Exact Byte-for-Byte .rodata Jump Tables & 46-Entry MonitorJni Registration Table
 *        Các bảng nhảy .rodata chuẩn xác từng byte & bảng đăng ký 46 hàm MonitorJni
 */

#include "monitorcollector_rodata_tables.h"

namespace bytedance {
namespace monitor {
namespace collector {

const uint8_t kCollectStateFieldJumpTable_038cf4[11] = {
    0x10, 0x1c, 0x28, 0x2e, 0x00, 0x00, 0x34, 0x00, 0x00, 0x16, 0x22
};

const uint8_t kA64GetImmJumpTable_038cff[7] = {
    0x00, 0x32, 0x00, 0x07, 0x32, 0x32, 0x11
};

const uint8_t kArm32ThumbDecodeJumpTables_038d06[68] = {
    0x00, 0x19, 0x00, 0x0c, 0x19, 0x19, 0x19, 0x19, 0x14, 0x00, 0x05, 0x12, 0x0a, 0x0c, 0x12, 0x12, 0x12, 0x0e, 0x11, 0x00, 0x02, 0x03, 0x03, 0x03, 0x00, 0x02, 0x00, 0x09, 0x0c, 0x11, 0x0d, 0x00, 0x00, 0x1b, 0x2d, 0x34, 0x40, 0x40, 0x3b, 0x3d, 0x2f, 0x5a, 0x31, 0x5a, 0x34, 0x44, 0x4a, 0x00, 0x13, 0x5a, 0x5a, 0x5a, 0x5a, 0x5a, 0x5a, 0x5a, 0x5a, 0x00, 0x13, 0x5a, 0x50, 0x5a, 0x5a, 0x55, 0x00, 0x1f, 0x00, 0x1f
};

const JniMethodEntry kMonitorJniTable_04c948[kMonitorJniMethodCount] = {
    {"doSetDebugMode", "(Z)V", 0x01498cULL},
    {"doInit", "()V", 0x014998ULL},
    {"doStart", "()V", 0x01499cULL},
    {"getProcInfos", "()Ljava/lang/String;", 0x0149a0ULL},
    {"dumpProcInfoTimeRangeToALog", "(JJ)V", 0x0149a4ULL},
    {"getProcInfoTimeRange", "(JJ)Ljava/lang/String;", 0x0149a8ULL},
    {"setBufferSize", "(I)V", 0x0149acULL},
    {"doCollect", "()V", 0x0149b0ULL},
    {"doStop", "()V", 0x0149b4ULL},
    {"doDestroy", "()V", 0x0149b8ULL},
    {"doGetCpuTime", "(I)J", 0x0149bcULL},
    {"doGetAppCpuTime", "()J", 0x0149c0ULL},
    {"getTotalCPUTimeByTimeInStat", "(I)J", 0x0149c4ULL},
    {"getThreadStatInfo", "(II)Lcom/bytedance/apm6/perf/base/model/ThreadStatInfo;", 0x0149c8ULL},
    {"doDumpNativeStack", "(I)Ljava/lang/String;", 0x0149ccULL},
    {"getProcCGroup", "(I)I", 0x0149d0ULL},
    {"doGetSchedInfo", "(I)Ljava/lang/String;", 0x0149d4ULL},
    {"doEnableAtrace", "(IJ)V", 0x0149d8ULL},
    {"doDisableAtrace", "()V", 0x0149f0ULL},
    {"doDumpAtrace", "()Ljava/lang/String;", 0x0149f4ULL},
    {"doDumpAtraceRangeToALog", "(JJ)V", 0x014a00ULL},
    {"doDumpAtraceRange", "(JJ)Ljava/lang/String;", 0x014a0cULL},
    {"enableLock", "(J)V", 0x014a18ULL},
    {"enableLockAll", "(JZ)V", 0x014a24ULL},
    {"disableLock", "()V", 0x014a34ULL},
    {"enableBinderHook", "()V", 0x014a38ULL},
    {"disableBinderHook", "()V", 0x014a3cULL},
    {"startHyperMonitor", "()V", 0x014a40ULL},
    {"stopHyperMonitor", "()V", 0x014a64ULL},
    {"setAlogInstance", "(J)V", 0x014a84ULL},
    {"keepProcHyperOpen", "(Z)V", 0x014a94ULL},
    {"readProcFile", "(Ljava/lang/String;[I[Ljava/lang/Object;[J[F)Z", 0x014aa0ULL},
    {"startOrStopAllocatedMonitor", "(ZLjava/lang/String;)Z", 0x014aa4ULL},
    {"setEnableAllocatedMonitor", "(ZIIIJLjava/lang/ClassLoader;)Z", 0x014b24ULL},
    {"clearAllocateInfo", "()V", 0x014b54ULL},
    {"initJavaMem", "()Z", 0x014b58ULL},
    {"getObjectsAllocatedEver", "()J", 0x014b70ULL},
    {"getBytesAllocatedEver", "()J", 0x014b74ULL},
    {"getMinorFaults", "()J", 0x014b78ULL},
    {"getMajorFaults", "()J", 0x014b7cULL},
    {"getGCCount", "()J", 0x014b80ULL},
    {"getGCTime", "()J", 0x014b84ULL},
    {"getBlockGCCount", "()J", 0x014b88ULL},
    {"getBlockGCTime", "()J", 0x014b8cULL},
    {"getAllocReportInfo", "()Ljava/nio/ByteBuffer;", 0x014b90ULL},
    {"releaseByteBuffer", "(J)V", 0x014b94ULL}
};

} // namespace collector
} // namespace monitor
} // namespace bytedance
