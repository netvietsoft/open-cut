# Clean-Room Reconstruction of `libwhisper.so` (Target 144 / 169)

## 1. Binary Overview / Tổng quan nhị phân
- **Library**: `libwhisper.so` (`38,584 bytes`)
- **SHA-256**: `03cd8fc0d2b50f1f7e0a6e77258eb704db5cb7c52a167c7581b4bce1f9b73406`
- **Architecture**: `AArch64` (`EM_AARCH64`, Little-Endian)
- **Exported C Symbols**: `InitWMInfo` (`0x1d1c`), `FreeWMInfo` (`0x2864`), `EmbedAudioChannelFloat` (`0x2894`), `EmbedAudioChannelInt16` (`0x2f68`)
- **Code Section**: `.text` at `0x0780..0x3788` (`12,296 bytes`, `3,074` AArch64 instructions across `13` subroutines)
- **Read-Only Data**: `.rodata` at `0x3790..0x7cc8` (`17,720 bytes` of GF(2^m) primitive polynomials, FFT twiddle tables, and psychoacoustic filter coefficients)
