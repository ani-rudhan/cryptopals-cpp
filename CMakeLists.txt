cmake_minimum_required(VERSION 3.10)
project(cryptopals-cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
    "${CMAKE_SOURCE_DIR}/utils"
    "${CMAKE_SOURCE_DIR}/Set-1/Challenge-1" 
    "${CMAKE_SOURCE_DIR}/Set-1/Challenge-2"
    "${CMAKE_SOURCE_DIR}/Set-1/Challenge-3"
    "${CMAKE_SOURCE_DIR}/Set-1/Challenge-4"
)

add_executable(hexToBase64 "Set-1/Challenge-1/main.cpp")
add_executable(fixedXOR "Set-1/Challenge-2/main.cpp")
add_executable(singleByteXORCipher "Set-1/Challenge-3/main.cpp")
add_executable(breakSingleCharacterXOR "Set-1/Challenge-4/breakSingleCharacterXOR.cpp")
add_executable(repeatingKeyXOR "Set-1/Challenge-5/main.cpp")
add_executable(breakRepeatingKeyXOR "Set-1/Challenge-6/main.cpp")

add_compile_definitions(
    FREQ_DIST_PATH="${CMAKE_SOURCE_DIR}/utils/freq_dist.csv"
    BREAK_SINGLE_KEY_XOR_INPUT_FILE_TXT_PATH="${CMAKE_SOURCE_DIR}/Set-1/Challenge-4/s1ch4.txt"
    BREAK_REPEATING_KEY_XOR_INPUT_FILE_TXT_PATH="${CMAKE_SOURCE_DIR}/Set-1/Challenge-6/s1ch6.txt"
)
