#include "Crypto.h"

std::string Crypto::encrypt(const std::string& text, int key) {
    std::string result = text;
    for (char& c : result) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            c = (c - base + key) % 26 + base;
        }
    }
    return result;
}

std::string Crypto::decrypt(const std::string& text, int key) {
    return Crypto::encrypt(text, 26 - (key % 26));
}
