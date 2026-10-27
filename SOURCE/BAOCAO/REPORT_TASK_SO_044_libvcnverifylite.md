# Clean-Room Reconstruction Analysis: `libvcnverifylite.so`
- **Target**: `140 / 169` (`TASK-179-RECONSTRUCTION-LIBVCNVERIFYLITE` / `TASK_SO_044_libvcnverifylite`)
- **Binary Size**: `34,640 bytes` (`34,640 B`)
- **SHA-256**: `9c1a1617357a0b640d2b159060c9d927cfdb4b430d6da55da8664004049fe93f`
- **Clean-Room C++17 Size**: `244,396 bytes` across `3` files (`0` stubs)
- **Unwind Table (`.eh_frame_hdr` @ `0x4a48`)**: `8` FDEs covering `0x1010..0x41f0` (`3,192` AArch64 instructions)
- **JNI Bridge**: `com/ss/mediakit/vcnlib/CustomVerify` (`doVerify([[BLjava/lang/String;Ljava/lang/String;)I`, `_init()V`)
