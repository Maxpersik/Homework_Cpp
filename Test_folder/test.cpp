#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "test.h"
#include "TestData.h"
#include <cmath>

std::string readFileContent(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл: " << filePath << '\n';
        return "";
    }
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    if (content.empty()) {
            std::cerr << "Файл пустой или нечитабельный: " << filePath << '\n';
        } else {
        std::cout << "Файл успешно прочитан: " << filePath << "\n";
        std::cout << "Первые 100 символов: " << content.substr(0, 100) << "\n";
    }
   
    return content;
}


void selectPredefinedTextPattern(std::string& text, std::string& pattern) {
    std::cout << "\nДоступные предустановленные наборы:\n";
    for (size_t i = 0; i < predefinedTextPatterns.size(); ++i) {
        std::cout << i + 1 << " - " << predefinedTextPatterns[i].first << '\n';
    }
    std::cout << "Выберите номер набора: ";
    int choice;
    std::cin >> choice;
    std::cin.ignore();

    if (choice >= 1 && choice <= predefinedTextPatterns.size()) {
        text = predefinedTextPatterns[choice - 1].first;
        pattern = predefinedTextPatterns[choice - 1].second;
    } else {
        std::cout << "Неверный выбор.\n";
    }
}

void executeTest(const std::string& text, const std::string& pattern, std::function<void(const std::string&, const std::string&)> method) {
    std::cout << "Тестирование текста: \"" << text << "\"\n";
    std::cout << "С шаблоном: \"" << pattern << "\"\n";
    method(text, pattern);
}

void runAllTests(std::function<void(const std::string&, const std::string&)> method) {
    for (const auto& [text, pattern] : predefinedTextPatterns) {
        executeTest(text, pattern, method);
        std::cout << "----------------------\n";
    }
}

void testMenu(std::function<void(const std::string&, const std::string&)> method) {
    while (true) {
        std::cout << "\nВыберите тест:\n";
        for (size_t i = 0; i < predefinedTextPatterns.size(); ++i) {
            std::cout << i + 1 << " - " << predefinedTextPatterns[i].first << '\n';
        }
        std::cout << "0 - Запустить все тесты\n";
        std::cout << "Выберите номер теста (или -1 для выхода): ";
        
        int choice;
        std::cin >> choice;
        std::cin.ignore();

        if (choice == -1) {
            break;
        } else if (choice == 0) {
            runAllTests(method);
            break;
        } else if (choice >= 1 && choice <= predefinedTextPatterns.size()) {
            executeTest(predefinedTextPatterns[choice - 1].first, predefinedTextPatterns[choice - 1].second, method);
        } else {
            std::cout << "Неверный выбор. Попробуйте снова.\n";
        }
    }
}

void printTestCases(const std::vector<std::pair<std::string, std::string>>& testCases) {
    fillTextPatternsFromFiles(predefinedTextPatterns, filePaths, "программа");
    for (size_t i = 0; i < testCases.size(); ++i) {
        const auto& [text, pattern] = testCases[i];
        std::cout << "Тест " << i + 1 << ":\n";
        std::cout << "Текст (первые 100 символов): " << text.substr(0, 100) << (text.size() > 100 ? "..." : "") << "\n";
        std::cout << "Шаблон: " << pattern << "\n";
        std::cout << "Длина текста: " << std::round(text.size() / 1.82 / 100) * 100 << " символов\n";
        std::cout << "--------------------------\n";
    }
}

void fillTextPatternsFromFiles(
    std::vector<std::pair<std::string, std::string>>& patterns,
    const std::vector<std::string>& filePaths,
    const std::string& pattern
) {
    for (const auto& filePath : filePaths) {
        std::string content = readFileContent(filePath);
        if (!content.empty()) {
            patterns.emplace_back(content, pattern);
        }
    }
}


