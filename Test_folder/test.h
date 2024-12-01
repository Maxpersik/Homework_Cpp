#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <fstream>

extern std::vector<std::pair<std::string, std::string>> predefinedTextPatterns;

std::string readFileContent(const std::string& filePath);

void selectPredefinedTextPattern(std::string& text, std::string& pattern);

void executeTest(const std::string& text, const std::string& pattern,
                 std::function<void(const std::string&, const std::string&)> method);

void runAllTests(std::function<void(const std::string&, const std::string&)> method);

void testMenu(std::function<void(const std::string&, const std::string&)> method);

#endif // TEST_H
