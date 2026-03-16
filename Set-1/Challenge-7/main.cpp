#include <fstream>
#include <iostream>
#include <sstream>
#include "openssl/evp.h"

#include "Base64Decode.hpp"

int main() {
    std::string fileInputStr;
    std::ifstream inFile(AES_ECB_ENCRYPTED_FILE_TXT_PATH);
    if (inFile.is_open()) {
        std::ostringstream os;
        os << inFile.rdbuf();
        fileInputStr = os.str();
    } else {
        std::cout << "Unable to open file\n";
    }

    auto decodedBytes = Base64DecodeToBytes(fileInputStr);
    
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    const unsigned char *key = reinterpret_cast<const unsigned char*>("YELLOW SUBMARINE");
    EVP_DecryptInit_ex(ctx, EVP_aes_128_ecb(), nullptr, key, nullptr);

    std::vector<unsigned char> plaintext(decodedBytes.size() + EVP_MAX_BLOCK_LENGTH);
    int outLen = 0;
    EVP_DecryptUpdate(ctx, plaintext.data(), &outLen, decodedBytes.data(), static_cast<int>(decodedBytes.size()));

    int finalLen = 0;
    EVP_DecryptFinal_ex(ctx, plaintext.data() + outLen, &finalLen);
    outLen += finalLen;

    EVP_CIPHER_CTX_free(ctx);

    std::cout.write(reinterpret_cast<const char*>(plaintext.data()), outLen);
    std::cout << '\n';
}