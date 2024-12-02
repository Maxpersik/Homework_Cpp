#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include "Utils/Utils.h"
#include "Test_folder/test.h"
#include "Starostin_algoritm/function_by_Starostin.h"
#include "Vodorezova_algoritm/function_by_Vodorezova.h"
#include "Gevorkyan_algoritm/function_by_Gevorkyan.h"
#include "Vardanyan_algoritm/function_by_Vardanyan.h"



void runAllAlgorithms(const std::vector<std::pair<std::string, std::string>>& testCases) {
    while (true) {
        std::cout << "\nВведите номер теста (1-" << testCases.size() << ") или 0 для выхода в главное меню: ";
        int testIndex;
        std::cin >> testIndex;

        if (testIndex == 0) {
            std::cout << "Возвращение в главное меню...\n";
            break;
        }

        if (testIndex < 1 || testIndex > testCases.size()) {
            std::cout << "Неверный номер теста. Попробуйте снова.\n";
            continue;
        }

        const auto& [text, pattern] = testCases[testIndex - 1];
        std::cout << "\nТестирование всех алгоритмов для выбранного теста:\n";
        std::cout << "Текст: \"" << text.substr(0, 100) << (text.size() > 100 ? "... (усечено)" : "") << "\"\n";
        std::cout << "Шаблон: \"" << pattern << "\"\n";

        // Z-алгоритм
        std::cout << "\nЗапуск Z-алгоритма:\n";
        bool zResult = measureExecutionTime(z_algoritm, text, pattern);
        std::cout << "Результат Z-алгоритма: " << (zResult ? "true" : "false") << "\n";

        // Алгоритм префиксного дерева
        std::cout << "\nЗапуск алгоритма префиксного дерева:\n";
        bool prefixResult = measureExecutionTime(prefix_code_by_Vodorezova, text, pattern);
        std::cout << "Результат алгоритма префиксного дерева: " << (prefixResult ? "true" : "false") << "\n";
        
        std::cout << "\nЗапуск Bitap алгоритма:\n";
        bool BitResult = measureExecutionTime(Bitap_Artur, text, pattern);
        std::cout << "Результат Bitap алгоритма: " << (BitResult ? "true" : "false") << "\n";
        
        std::cout << "\nЗапуск KMP алгоритма:\n";
        bool KMPResult = measureExecutionTime(KMP_Search, text, pattern);
        std::cout << "Результат KMP алгоритма: " << (KMPResult ? "true" : "false") << "\n";

        // Если добавлены другие алгоритмы
        // std::cout << "\nЗапуск другого алгоритма:\n";
        // bool otherResult = measureExecutionTime(otherAlgorithm, text, pattern);
        // std::cout << "Результат другого алгоритма: " << (otherResult ? "true" : "false") << "\n";

        std::cout << "\nТест завершён. Вы можете выбрать другой тест или выйти в главное меню.\n";
    }
}

std::vector<std::string> getMenuOptions = {
        "Выход",
        "Алгоритм Кнута-Морриса-Пратта",
        "Поиск с помощью префиксного дерева",
        "Z-алгоритм",
        "Алгоритм Bitap",
        "Все алгоритмы",
        "Показать все тесты"
    };



int main() {
    std::string command;
    long value;
    printTestCases(predefinedTextPatterns);

    while (true) {
        displayMenu(getMenuOptions);
        getline(std::cin, command);
        
        value = numberOrDefault(command);

        
        switch (value) {
            case 1:
                universalMenu("KMP алгоритм:", KMP_Search, predefinedTextPatterns);
                break;
            case 2:
                universalMenu("Алгоритм префиксного дерева: ", prefix_code_by_Vodorezova, predefinedTextPatterns);
                break;
            case 3:
                universalMenu("Z-алгоритм:", z_algoritm, predefinedTextPatterns);
                break;
            case 4:
                universalMenu("Bitap алгоритм", Bitap_Artur, predefinedTextPatterns);
                break;
            case 5:
                runAllAlgorithms(predefinedTextPatterns);
                break;
            case 6:
                printTestCases(predefinedTextPatterns);
                break;
            case 0:
                std::cout << "Выход из программы.\n";
                return 0;
            default:
                std::cout << "Неверный выбор. Попробуйте снова.\n";
                break;
        }
    }
}
    



