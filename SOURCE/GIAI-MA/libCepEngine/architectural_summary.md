# ARCHITECTURAL SUMMARY — `libCepEngine.so` (Target 45)

## 1. Overview (Tổng quan Kiến trúc)
- **English**: `libCepEngine.so` (`362,464 bytes`, ELF64 AArch64) is ByteDance Pitaya's native **Complex Event Processing (CEP) NFA & Rule Engine** (`namespace cep`, engine version `"1.5.0"`, `ApiVersion() == 2`). It evaluates stateful temporal event patterns over real-time telemetry streams (`states`, `edges`, `targetState`, `actionType`, `within`, `skipStrategy`, `$finalState$`, `$stopState$`) and dispatches pattern-match callbacks to both C++ consumers (`libTTMStrategyCenter.so`) and Kotlin/Java (`com.bytedance.pitaya.cep_engine.CepEngineManager`).
- **Tiếng Việt**: `libCepEngine.so` (`362,464 bytes`, ELF64 AArch64) là **Bộ máy Xử lý Sự kiện Phức hợp (CEP) và Ô-tô-mát Hữu hạn Không đơn định (NFA)** (`namespace cep`, phiên bản `"1.5.0"`, `ApiVersion() == 2`) của ByteDance Pitaya. Thư viện đánh giá các chuỗi sự kiện theo thời gian thực và kích hoạt callback tới cả tầng C++ (`libTTMStrategyCenter.so`) lẫn tầng Kotlin/Java (`com.bytedance.pitaya.cep_engine.CepEngineManager`).

## 2. Key Subsystems & AArch64 Address Map
| Subsystem | Address Range | Key Symbols & Responsibilities |
|---|---|---|
| **API & Polymorphic Data** | `0x0c33c..0x0c767` | `ApiVersion()` (`0x0c33c` -> `2`), `DefaultContext::GetShared()` (`0x0c358`), `DataInterface` (`0x0c4e8..0x0c764`, vtable `_ZTVN3cep13DataInterfaceE` @ `0x5a9d8`, types `0..6`) |
| **Debug & Transition Info** | `0x0c768..0x0cba7` | `DebugInfo` (`+0x08 biz_name_`, `+0x20 rule_name_`), `ValueInfo` (`+0x38 tag_`, `+0x50 value_`), `MatchTransitionInfo`, `TransitionInfo` (`+0x68 trigger_type_`, `+0x70 event_`, `+0x80 advance_time_`) |
| **EngineConfig & EngineResult** | `0x13a48..0x14f1b` | `EngineConfig` (`104 B` struct, `SetExtra`..`ParseFromData` @ `0x13cd0`), `EngineResult` (`0x14e3c..0x14f10`) |
| **EngineCore & EngineManagerInner** | `0x15564..0x1b59f` | `EngineCore` (`0x15564..0x15d70`), `EngineManagerInner::Instance()` (`0x16608`, `.bss 0x5c038`), `CollectCrashInfo` (`0x1b0c0`) |
| **EngineManager & Env** | `0x21d90..0x246e3` | `EngineManager::Instance()` (`0x21d90`, `.bss 0x5c548`), `Env::Instance()` (`0x243a8`, `.bss 0x5c558`, `"1.5.0"`, window `300000 ms` = `0x493e0`) |
| **Error & NFA State Machine** | `0x25ac8..0x32453` | `Error` (`0x26404..0x269e4`, 22 `ErrorCode` messages), `EventWrapper` (`0x27924`), `EventWrapperList` (`0x27a10`, `Type() = 100`), `ExprEvaluator` (`0x285d8`), `Match` (`0x286d0`), `Nfa::Process` (`0x2d2c8`), `Nfa::AdvanceTime` (`0x2d748`), `Result` (`0x320b8`) |
| **DSL, Concurrency & JNI Bridge** | `0x40f88..0x4a44f` | `GetInt`..`GetDict` (`0x40f88..0x41cac`), `GetCurrentTimestamp` (`0x41e94`, magic `0x20c49ba5e353f7cf`), `CheckDSLVersion` (`0x420dc`), `ParseKeyChain` (`0x4226c`), `RWLock`/`Semaphore` (`0x42ee0..0x43410`), `NativeData` (`0x44468..0x47344`), `CBlockContainer` (`0x489d4`), 13 JNI exports (`0x49250..0x4a3b8`) |
