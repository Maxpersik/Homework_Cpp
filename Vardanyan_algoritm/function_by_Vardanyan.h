#pragma once
#include <vector>
#include <string>

bool KMP_Search(const std::string& text, const std::string& pattern);

std::vector<int> ComputePrefixFunction(const std::string& pattern);
