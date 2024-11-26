#include <iostream>
#include <string>
#include <vector>
#include <fstream>

std::string readFileContent(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл: " << filePath << '\n';
        return "";
    }
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    return content;
}

std::vector<std::pair<std::string, std::string>> predefinedTextPatterns = {
    {"Тест 1: Простой пример текста, содержащего шаблон.", "шаблон"}, // Прямое совпадение
    {"Тест 2: Этот текст не содержит нужного шаблона.", "шаблон"},     // Шаблон отсутствует
    {"Тест 3: ", "шаблон"},                                            // Пустой текст, непустой шаблон
    {"Тест 4: Пример текста.", ""},                                    // Непустой текст, пустой шаблон
    {"Тест 5: ", ""},                                                  // Пустой текст и пустой шаблон
    {"Тест 6: шаблон в начале текста", "шаблон"},                      // Шаблон в начале текста
    {"Тест 7: Текст с шаблоном в конце.", "конце."},                   // Шаблон в конце текста
    {"Тест 8: ааабббвввгггддд", "ббб"},                                // Повторяющиеся символы
    {"Тест 9: Это длинный текст с кратким шаблоном внутри.", "шаблон"}, // Длинный текст, короткий шаблон
    {"Тест 10: Короткий", "Короткий длинный шаблон"},                  // Короткий текст, длинный шаблон
    {"Тест 11: Проверка регистра шаблона", "Шаблон"},
    {readFileContent("file1.txt"), "шаблон"}// Различие в регистре
};

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
            break;  // Возвращаемся в главное меню
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

