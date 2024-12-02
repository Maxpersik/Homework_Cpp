#include <iostream>
#include <unordered_map>
#include <cstdint>
#include "function_by_Gevorkyan.h"
using namespace std;

bool Bitap_Artur(const string& text, const string& pattern) {
    const int m = pattern.size();
    const int n = text.size();

    if (m > 64) {
        cerr << "Error: Pattern length exceeds 64 characters, which is not supported in this implementation.\n";
        return false;
    }

    unordered_map<char, uint64_t> bitmask;
    for (int i = 0; i < m; ++i) {
        bitmask[pattern[i]] |= (1ULL << i);
    }

    uint64_t currentState = 0;

    for (int i = 0; i < n; ++i) {
        currentState = ((currentState << 1) | 1) & bitmask[text[i]];

        if (currentState & (1ULL << (m - 1))) {
            return true;
        }
    }
    return false;
}