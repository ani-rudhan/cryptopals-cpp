#pragma once

#include <string>

#include "HexDecode.hpp"
#include "Base64Encode.hpp"

inline std::string HexToBase64(const std::string &hexStr)
{
    return Base64Encode(HexDecodeToString(hexStr));
}
