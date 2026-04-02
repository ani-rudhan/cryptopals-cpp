# cryptopals-cpp

C++ solutions for the [Cryptopals Crypto Challenges](https://cryptopals.com/), organized by set and challenge. Each solution is accompanied by a write-up on my blog — [Signal to Shell](https://anirudhan.hashnode.dev/) — covering the cryptographic concepts, algorithms, and design decisions behind the implementation.

## Blog Series

**[std::crypto | Solving Cryptopals](https://anirudhan.hashnode.dev/series/cryptopals-cpp)**

| Post | Challenges Covered |
|------|-------------------|
| [Binary Encodings: From Bits to Bytes](https://anirudhan.hashnode.dev/binary-encodings) | Background: hex vs base64 vs decimal |
| [Hex Encoding and Decoding](https://anirudhan.hashnode.dev/hex-transforms) | Byte-first hex encode/decode |
| [Base64 Encoding and Decoding](https://anirudhan.hashnode.dev/base64-transforms) | 6-bit regrouping, padding |
| [From Encodings to XOR: Building the Foundations of Cryptography](https://anirudhan.hashnode.dev/transforms-and-fixed-xor) | Set 1 — Challenges 1 & 2 |
| [Breaking Single Byte XOR encryption](https://anirudhan.hashnode.dev/breaking-single-byte-xor-encryption) | Set 1 — Challenges 3 & 4 |
| [Breaking Repeating Key XOR encryption](https://anirudhan.hashnode.dev/breaking-repeating-key-xor-encryption) | Set 1 — Challenges 5 & 6 |

## Challenges

### Set 1 — The Basics

| # | Title | Binary | Key Concepts |
|---|-------|--------|--------------|
| 1 | Hex to Base64 | `hexToBase64` | Hex decode → Base64 encode |
| 2 | Fixed XOR | `fixedXOR` | Byte-level XOR of equal-length buffers |
| 3 | Single-byte XOR cipher | `singleByteXORCipher` | Chi-square frequency scoring, brute-force 256-key search |
| 4 | Detect single-character XOR | `breakSingleCharacterXOR` | Apply challenge 3 scoring across 327 ciphertexts |
| 5 | Implement repeating-key XOR | `repeatingKeyXOR` | Cyclic key XOR encryption |
| 6 | Break repeating-key XOR | `breakRepeatingKeyXOR` | Hamming distance key-size detection, transposition attack |
| 7 | AES in ECB mode | `aes-ecb` | AES-128-ECB decryption via OpenSSL |
| 8 | Detect AES in ECB mode | `detect-aes-ecb` | Identifying repeated 16-byte blocks |

## Repository Layout

```
Set-1/
  Challenge-N/        # entrypoint (main.cpp) and challenge-specific headers
Set-2/
  Challenge-N/
utils/                # shared encoding, decoding, scoring, and distance helpers
lib/openssl-3.6.1/    # local OpenSSL build (AES support)
build/                # CMake build artifacts and compiled binaries
```

### Key Utilities (`utils/`)

| File | Purpose |
|------|---------|
| `HexEncode.hpp` / `HexDecode.hpp` | Hex ↔ byte array conversion |
| `Base64Encode.hpp` / `Base64Decode.hpp` | Base64 ↔ byte array conversion |
| `GetCharCount.hpp` | Character frequency counting |
| `GetExpectedFreqDistMap.hpp` | Reference English frequency distribution |
| `GetHammingDistance.hpp` | Bitwise Hamming distance between byte arrays |
| `ReadFile.hpp` | File I/O helper |

## Build

Requires CMake 3.15+ and a C++17-capable compiler.

```bash
cmake -S . -B build
cmake --build build
```

## Run

```bash
./build/hexToBase64
./build/fixedXOR
./build/singleByteXORCipher
./build/breakSingleCharacterXOR
./build/repeatingKeyXOR
./build/breakRepeatingKeyXOR
./build/aes-ecb
./build/detect-aes-ecb
```
