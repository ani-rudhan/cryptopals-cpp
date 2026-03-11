# cryptopals-cpp

C++ solutions for Cryptopals Set 1, organized by challenge with shared utility headers.

## Layout

- `Set-1/Challenge-1..6`: challenge entrypoints and challenge-specific helpers.
- `utils/`: reusable encoding, decoding, frequency, and distance helpers.
- `build/`: local build artifacts.

## Build

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
```
