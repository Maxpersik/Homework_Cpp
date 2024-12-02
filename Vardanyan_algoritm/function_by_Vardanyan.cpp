#include "function_by_Vardanyan.h"
#include <vector>
#include <string>
#include <iostream>

std::vector<int> ComputePrefixFunction(const std::string& pattern) {
    int m = pattern.size();
    std::vector<int> prefix(m, 0);
    int k = 0;

    for (int i = 1; i < m; ++i) {
        while (k > 0 && pattern[k] != pattern[i]) {
            k = prefix[k - 1];
        }
        if (pattern[k] == pattern[i]) {
            ++k;
        }
        prefix[i] = k;
    }
    return prefix;
}

bool KMP_Search(const std::string& text, const std::string& pattern) {
    int n = text.size();
    int m = pattern.size();

    if (m == 0 || n == 0) {
        return false;
    }

    std::vector<int> prefix = ComputePrefixFunction(pattern);
    int q = 0;

    for (int i = 0; i < n; ++i) {
        while (q > 0 && pattern[q] != text[i]) {
            q = prefix[q - 1];
        }
        if (pattern[q] == text[i]) {
            ++q;
        }
        if (q == m) {
            return true;
        }
    }
    return false;
}
