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
auto measureExecutionTime(Func&& func, Args&&... args) {
    using namespace std::chrono;

    auto start = high_resolution_clock::now(); // Начало измерения времени
    auto result = std::invoke(std::forward<Func>(func), std::forward<Args>(args)...);
    auto end = high_resolution_clock::now();   // Конец измерения времени

    auto duration = duration_cast<microseconds>(end - start).count();
    std::cout << "Execution time: " << duration << " microseconds\n";

    return result; // Возвращаем результат вызова функции
}

template <typename Func>
void universalMenu(
    const std::string& menuName,
    Func algorithmFunction, // Шаблонная функция для алгоритма
    const std::vector<std::pair<std::string, std::string>>& testCases
) {
    while (true) {
        std::cout << "\nМеню: " << menuName << "\n";
        std::cout << "0. Вернуться в главное меню\n";
        std::cout << "1. Запустить на всех тестах с измерением времени\n";

        // Показать все тесты
        for (size_t i = 0; i < testCases.size(); ++i) {
            std::cout << i + 2 << ". Тест " << i + 1 << ": \"" << testCases[i].second << "\"\n";
        }

        std::cout << "Выберите опцию: ";
        int choice;
        std::cin >> choice;

        if (choice == 0) {
            std::cout << "Возврат в главное меню.\n";
            break;
        } else if (choice == 1) {
            std::cout << "Запуск алгоритма на всех тестах с измерением времени...\n";
            for (size_t i = 0; i < testCases.size(); ++i) {
                const auto& [text, pattern] = testCases[i];
                std::cout << "\nТест " << i + 1 << ": \"" << pattern << "\" -> ";
                
                // Измерение времени выполнения алгоритма
                auto result = measureExecutionTime(algorithmFunction, text, pattern);
                std::cout << (result ? "true" : "false") << "\n";
            }
        } else if (choice >= 2 && choice < static_cast<int>(testCases.size() + 2)) {
            size_t testIndex = choice - 2;
            const auto& [text, pattern] = testCases[testIndex];
            std::cout << "\nЗапуск алгоритма на тесте " << testIndex + 1 << ": \"" << pattern << "\" -> ";
            
            // Измерение времени выполнения для одного теста
            auto result = measureExecutionTime(algorithmFunction, text, pattern);
            std::cout << (result ? "true" : "false") << "\n";
        } else {
            std::cout << "Неверный выбор. Попробуйте снова.\n";
        }
    }
}


#endif
