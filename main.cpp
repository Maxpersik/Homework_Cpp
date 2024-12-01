#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include "Utils/Utils.h"
#include "Test_folder/test.h"
#include "Starostin_algoritm/function_by_Starostin.h"

std::vector<std::string> getMenuOptions = {
        "Выход",
        "Алгоритм Кнута-Морриса-Пратта",
        "Поиск с помощью префиксного дерева",
        "Z-алгоритм",
        "Алгоритм Bitap",
        "Все алгоритмы"
    };

int main() {
    std::string command;
    long value;
    while (true) {
        displayMenu(getMenuOptions);
        getline(std::cin, command);
        
        value = numberOrDefault(command);
        
        switch (value) {
            case 1:
                //universalMenu("Пример алгоритма", exampleAlgorithm, testCases);
                break;
            case 2:
                //universalMenu("Пример алгоритма", exampleAlgorithm, testCases)
                break;
            case 3:
                //universalMenu("Z-алгоритм:", find, predefinedTextPatterns);
                break;
            case 4:
                //universalMenu("Пример алгоритма", exampleAlgorithm, testCases);
                break;
            case 5:
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
    

