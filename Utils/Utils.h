#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <ctime>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <chrono>
#include <functional>
#include <vector>


using namespace std;

long numberOrDefault(const string &input);
bool isNumber(const std::string& s);
void displayMenu(const std::vector<std::string>& options);

template <typename Func, typename... Args>
auto measureExecutionTime(Func&& func, Args&&... args);
template <typename Func>
void universalMenu(
    const std::string& menuName,
    Func algorithmFunction,
    const std::vector<std::pair<std::string, std::string>>& testCases
);


#endif
