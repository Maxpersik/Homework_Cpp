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

using namespace std;

extern std::vector<string> getMenuOptions;

long numberOrDefault(const string &input);
bool isNumber(const std::string& s);
void displayMenu(const std::vector<std::string>& options);

template <typename Func, typename... Args>
auto measureExecutionTime(Func&& func, Args&&... args);

#endif
